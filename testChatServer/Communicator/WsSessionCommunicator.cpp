#include "WsSessionCommunicator.hpp"

#include "ChatMessageWrapper.hpp"

WsSessionCommunicator::WsSessionCommunicator(WsSocketType socket)
    : socket_(std::move(socket)), timer_(socket_.next_layer().get_executor()) {
    socket_.binary(true);
}

boost::asio::any_io_executor WsSessionCommunicator::getExecutor() {
    return socket_.get_executor();
}

boost::asio::awaitable<ChatMessageWrapper> WsSessionCommunicator::asyncRead() {
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
    co_return;
}

void WsSessionCommunicator::cancelOne() { timer_.cancel_one(); }

void WsSessionCommunicator::stop() {
    socket_.async_close(boost::beast::websocket::close_reason(
                            boost::beast::websocket::close_code::normal),
                        [](boost::system::error_code const& ec) {});
    timer_.cancel();
}
