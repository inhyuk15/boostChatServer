#ifndef Server_hpp
#define Server_hpp

#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>

#include "Session.hpp"

using boost::asio::ip::tcp;

class Server {
	 public:
	Server(boost::asio::io_context& io_context, tcp::endpoint& endpoint);
	void accept();

	 private:
		tcp::acceptor acceptor_;
};

#endif /* Server_hpp */
