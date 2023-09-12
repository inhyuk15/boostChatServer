#include "TcpServerCommunicator.hpp"

#include "TcpSessionCommunicator.hpp"

TcpServerCommunicator::TcpServerCommunicator(
    boost::asio::io_context& io_context, tcp::endpoint& endpoint)
    : BaseServerCommunicator(io_context, endpoint) {}

boost::asio::awaitable<std::shared_ptr<BaseSessionCommunicator>>
TcpServerCommunicator::asyncAccept() {
    auto socket = co_await acceptor_.async_accept(boost::asio::use_awaitable);
    std::shared_ptr<BaseSessionCommunicator> sessionCommunicator =
        std::make_shared<TcpSessionCommunicator>(std::move(socket));

    co_return sessionCommunicator;
}
