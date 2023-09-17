#ifndef WebSocketCommunicator_hpp
#define WebSocketCommunicator_hpp

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>

#include "BaseServerCommunicator.hpp"

using namespace boost::beast;
using namespace boost::beast::websocket;

class WsSessionCommunicator;

class WsServerCommunicator : public BaseServerCommunicator<WsSessionCommunicator> {
public:
	WsServerCommunicator(boost::asio::io_context& io_context, const tcp::endpoint& endpoint);
	boost::asio::awaitable<std::shared_ptr<WsSessionCommunicator>> asyncAccept() override;
	
	boost::asio::awaitable<void> handshake();
};

#endif /* WebSocketCommunicator_hpp */
