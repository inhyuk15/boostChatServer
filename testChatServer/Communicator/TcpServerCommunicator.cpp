#include "TcpServerCommunicator.hpp"

#include "TcpSessionCommunicator.hpp"

TcpServerCommunicator::TcpServerCommunicator(
    boost::asio::io_context& io_context, const tcp::endpoint& endpoint)
    : BaseServerCommunicator(io_context, endpoint) {}

boost::asio::awaitable<std::shared_ptr<TcpSessionCommunicator>>
TcpServerCommunicator::asyncAccept() {
    auto socket = co_await acceptor_.async_accept(boost::asio::use_awaitable);
    auto sessionCommunicator =
        std::make_shared<TcpSessionCommunicator>(std::move(socket));

    co_return sessionCommunicator;
}
