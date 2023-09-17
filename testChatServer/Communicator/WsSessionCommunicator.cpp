// #include "WsSessionCommunicator.hpp"
//
// #include "ChatMessageWrapper.hpp"
//
// WsSessionCommunicator::WsSessionCommunicator(tcp::socket socket)
//     : BaseSessionCommunicator(std::move(socket)) {}
//
// tcp::socket::executor_type WsSessionCommunicator::getExecutor() {
//     return socket_.get_executor();
// }
//
// boost::asio::awaitable<ChatMessageWrapper> WsSessionCommunicator::asyncRead()
// {
//     uint32_t networkDataSize;
//     co_await boost::asio::async_read(
//         socket_, boost::asio::buffer(&networkDataSize,
//         sizeof(networkDataSize)), use_awaitable);
//
//     std::size_t dataSize = ntohl(networkDataSize);
//
//     std::string binaryData(dataSize, '\0');
//     co_await boost::asio::async_read(socket_,
//     boost::asio::buffer(binaryData),
//                                      use_awaitable);
//     ChatMessageWrapper chatMessage;
//     chatMessage.decode(binaryData);
//
//     co_return chatMessage;
// }
//
// boost::asio::awaitable<void> WsSessionCommunicator::asyncWrite(
//     const std::string& sendBytes) {
//     uint32_t dataSize = static_cast<uint32_t>(sendBytes.size());
//     dataSize = htonl(dataSize);
//
//     co_await boost::asio::async_write(
//         socket_, boost::asio::buffer(&dataSize, sizeof(dataSize)),
//         use_awaitable);
//
//     co_await boost::asio::async_write(socket_,
//     boost::asio::buffer(sendBytes),
//                                       use_awaitable);
//
//     co_return;
// }
//
// boost::asio::awaitable<void> WsSessionCommunicator::asyncWait() {
//     boost::system::error_code ec;
//     co_await timer_.async_wait(redirect_error(use_awaitable, ec));
// }
//
// void WsSessionCommunicator::cancelOne() { timer_.cancel_one(); }
//
// void WsSessionCommunicator::stop() {
//     socket_.close();
//     timer_.cancel();
// }
