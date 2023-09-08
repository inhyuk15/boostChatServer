#include "Session.hpp"

#include "Room.hpp"

Session::Session(tcp::socket socket, std::shared_ptr<Room> room)
    : socket_(std::move(socket)), room_(room), timer_(socket_.get_executor()) {
    timer_.expires_at(std::chrono::steady_clock::time_point::max());
}

void Session::start() {
    co_spawn(
        socket_.get_executor(),
        [self = shared_from_this()]() { return self->startRead(); }, detached);
    co_spawn(
        socket_.get_executor(),
        [self = shared_from_this()] { return self->write(); }, detached);
}

boost::asio::awaitable<void> Session::readNickname() {
    try {
        std::string readMsg;
        std::size_t n = co_await boost::asio::async_read_until(
            socket_, boost::asio::dynamic_buffer(readMsg, 1024), "\n",
            use_awaitable);
        nickname_ = readMsg.substr(0, n - 1);
    } catch (std::exception&) {
        stop();
    }
}
boost::asio::awaitable<void> Session::readMsg() {
    try {
        for (std::string readMsg;;) {
            uint32_t networkDataSize;
            co_await boost::asio::async_read(
                socket_,
                boost::asio::buffer(&networkDataSize, sizeof(networkDataSize)),
                use_awaitable);

            std::size_t dataSize = ntohl(networkDataSize);

            std::string binaryData(dataSize, '\0');
            co_await boost::asio::async_read(
                socket_, boost::asio::buffer(binaryData), use_awaitable);
            ChatMessageWrapper chatMessage;
            chatMessage.decode(binaryData);

            std::cout << "Username: " << chatMessage.getUserName() << std::endl;
            std::cout << "Timestamp: " << chatMessage.getTimestamp()
                      << std::endl;
            if (chatMessage.getDataType() == chat::TEXT) {
                room_->deliver(chatMessage);
                std::cout << "Message: " << chatMessage.getMessageText()
                          << std::endl;
            } else if (chatMessage.getDataType() == chat::IMAGE) {
                std::cout << " image" << std::endl;
            }
        }
    } catch (std::exception&) {
        stop();
    }
}

boost::asio::awaitable<void> Session::startRead() {
    try {
        //                co_await readNickname();
        room_->join(shared_from_this());
        co_await readMsg();
    } catch (std::exception&) {
        stop();
    }
}

void Session::deliver(const std::string& msg) {
    std::cout << "msg " << msg << std::endl;
    writeMsgs_.push_back(msg);
    timer_.cancel_one();
}

void Session::deliver(const ChatMessageWrapper& msg) {
    std::cout << "msg " << msg.getUserName() << std::endl;
    writeMsgs2_.push_back(msg);
    timer_.cancel_one();
}

boost::asio::awaitable<void> Session::write() {
    try {
        while (socket_.is_open()) {
            if (writeMsgs2_.empty()) {
                boost::system::error_code ec;
                co_await timer_.async_wait(redirect_error(use_awaitable, ec));
            } else {
                auto sendBytes = writeMsgs2_.front().encode();
                uint32_t dataSize = static_cast<uint32_t>(sendBytes.size());
                dataSize = htonl(dataSize);

                co_await boost::asio::async_write(
                    socket_, boost::asio::buffer(&dataSize, sizeof(dataSize)),
                    use_awaitable);

                co_await boost::asio::async_write(
                    socket_, boost::asio::buffer(sendBytes), use_awaitable);
                writeMsgs2_.pop_front();
            }
        }
    } catch (std::exception& e) {
        stop();
    }
}

void Session::stop() {
    room_->leave(shared_from_this());
    socket_.close();
    timer_.cancel();
}

std::string Session::nickname() { return nickname_; }
