#ifndef TcpServer_hpp
#define TcpServer_hpp

#include <boost/asio.hpp>

#include <cstdlib>
#include <iostream>
#include <set>

#include "Server.hpp"

using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::co_spawn;
using boost::asio::detached;
using boost::asio::use_awaitable;

class Room;

class TcpServer : public Server {
	 public:
		TcpServer(boost::asio::io_context& io_context, tcp::endpoint& endpoint);
		boost::asio::awaitable<void> accept() override;
};

#endif /* TcpServer_hpp */
