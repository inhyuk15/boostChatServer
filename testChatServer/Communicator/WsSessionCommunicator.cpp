#include "WsSessionCommunicator.hpp"

#include "ChatMessageWrapper.hpp"

WsSessionCommunicator::WsSessionCommunicator(WsSocketType socket)
    : BaseSessionCommunicator(std::move(socket)) {}

boost::asio::any_io_executor WsSessionCommunicator::getExecutor() {
    return socket_.get_executor();
}

boost::asio::awaitable<ChatMessageWrapper> WsSessionCommunicator::asyncRead() {
    //    uint32_t networkDataSize;
    //    co_await boost::asio::async_read(
    //        socket_, boost::asio::buffer(&networkDataSize,
    //        sizeof(networkDataSize)), use_awaitable);
    //
    //    std::size_t dataSize = ntohl(networkDataSize);
    //
    //    std::string binaryData(dataSize, '\0');
    //    co_await boost::asio::async_read(socket_,
    //    boost::asio::buffer(binaryData),
    //                                     use_awaitable);
    //    ChatMessageWrapper chatMessage;
    //    chatMessage.decode(binaryData);
    //
    //    co_return chatMessage;
    boost::beast::flat_buffer buffer;
    co_await socket_.async_read(buffer, boost::asio::use_awaitable);

    const std::string binaryData =
        boost::beast::buffers_to_string(buffer.data());
    ChatMessageWrapper chatMessage;
    chatMessage.decode(binaryData);

    co_return chatMessage;
}

boost::asio::awaitable<void> WsSessionCommunicator::asyncWrite(
    const std::string& sendBytes) {
    co_await socket_.async_write(boost::asio::buffer(sendBytes),
                                 boost::asio::use_awaitable);
    co_return;
}

boost::asio::awaitable<void> WsSessionCommunicator::asyncWait() {
    boost::system::error_code ec;
    co_await timer_.async_wait(redirect_error(use_awaitable, ec));
}

void WsSessionCommunicator::cancelOne() { timer_.cancel_one(); }

void WsSessionCommunicator::stop() {
    //     socket_.close();
    timer_.cancel();
}
