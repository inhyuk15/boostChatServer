#include "TcpSessionCommunicator.hpp"

#include "ChatMessageWrapper.hpp"

TcpSessionCommunicator::TcpSessionCommunicator(tcp::socket socket)
    : socket_(std::move(socket)), timer_(socket.get_executor())
{
    timer_.expires_at(std::chrono::steady_clock::time_point::max());
}

tcp::socket::executor_type TcpSessionCommunicator::getExecutor()
{
    return socket_.get_executor();
}

boost::asio::awaitable<ChatMessageWrapper> TcpSessionCommunicator::asyncRead()
{
    //    auto start_time = std::chrono::high_resolution_clock::now();

    uint32_t networkDataSize;
    co_await boost::asio::async_read(socket_, boost::asio::buffer(&networkDataSize, sizeof(networkDataSize)),
                                     use_awaitable);

    boost::asio::socket_base::receive_buffer_size recv_option;
    socket_.get_option(recv_option);
    int recv_buffer_size = recv_option.value();
    //    std::string bfSizeMsg = "Current receive buffer size: " + std::to_string(recv_buffer_size);
    //    LogMessage logMessage(getCurTimestamp(), bfSizeMsg);
    //
    //    LogManager::getInstance().logMessage(LogManager::EventType::ChatEvent, logMessage);

    std::size_t dataSize = ntohl(networkDataSize);

    std::string binaryData(dataSize, '\0');
    co_await boost::asio::async_read(socket_, boost::asio::buffer(binaryData), use_awaitable);

    //    auto end_time = std::chrono::high_resolution_clock::now();
    //    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time); //
    //    std::string elapsedTimeMsg = "Time taken to receive message: " + std::to_string(elapsed.count()) + "ms";
    //    LogManager::getInstance().logMessage(LogManager::EventType::ChatEvent,
    //                                         LogMessage(getCurTimestamp(), elapsedTimeMsg));

    ChatMessageWrapper chatMessage;
    chatMessage.decode(binaryData);

    co_return chatMessage;
}

boost::asio::awaitable<void> TcpSessionCommunicator::asyncWrite(const std::string &sendBytes)
{
    uint32_t dataSize = static_cast<uint32_t>(sendBytes.size());
    dataSize = htonl(dataSize);

    co_await boost::asio::async_write(socket_, boost::asio::buffer(&dataSize, sizeof(dataSize)), use_awaitable);

    co_await boost::asio::async_write(socket_, boost::asio::buffer(sendBytes), use_awaitable);

    co_return;
}

boost::asio::awaitable<void> TcpSessionCommunicator::asyncWait()
{
    boost::system::error_code ec;
    co_await timer_.async_wait(redirect_error(use_awaitable, ec));
}

void TcpSessionCommunicator::cancelOne()
{
    timer_.cancel_one();
}

void TcpSessionCommunicator::stop()
{
    socket_.close();
    timer_.cancel();
}
