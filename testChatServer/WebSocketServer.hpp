#ifndef WebSocketServer_hpp
#define WebSocketServer_hpp

#include "Server.hpp"
#include <boost/beast/websocket.hpp>

class WebSocketServer : public Server {
public:
	WebSocketServer(boost::asio::io_context& io_context, tcp::endpoint& endpoint);

//		boost::asio::awaitable<void> accept() override;
	
};

#endif /* WebSocketServer_hpp */
