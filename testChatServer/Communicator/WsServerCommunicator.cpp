#include "WsServerCommunicator.hpp"

#include "WsSessionCommunicator.hpp"

WsServerCommunicator::WsServerCommunicator(boost::asio::io_context &io_context, const tcp::endpoint &endpoint)
    : BaseServerCommunicator(io_context, endpoint)
{
}

boost::asio::awaitable<std::shared_ptr<WsSessionCommunicator>> WsServerCommunicator::asyncAccept()
{
    boost::beast::tcp_stream stream(io_context_);
    co_await acceptor_.async_accept(stream.socket(),
                                    use_awaitable); // tcp connection
    boost::beast::websocket::stream<boost::beast::tcp_stream> ws(std::move(stream));

    co_await ws.async_accept(use_awaitable); // handshaking

    std::shared_ptr<WsSessionCommunicator> sessionCommunicator = std::make_shared<WsSessionCommunicator>(std::move(ws));

    co_return sessionCommunicator;
}
