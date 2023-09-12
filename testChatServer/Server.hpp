#ifndef Server_hpp
#define Server_hpp

#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <set>

using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::co_spawn;
using boost::asio::detached;
using boost::asio::use_awaitable;

class Room;

class Server : public std::enable_shared_from_this<Server> {
public:
	virtual ~Server() = default;
	virtual boost::asio::awaitable<void> accept() = 0;
	
protected:
		boost::asio::io_context& io_context_;
		std::shared_ptr<Room> room_;
		
		Server(boost::asio::io_context& io_context, const tcp::endpoint& endpoint)
				: io_context_(io_context) {}
};


#endif
