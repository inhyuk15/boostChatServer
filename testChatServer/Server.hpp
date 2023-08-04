#ifndef Server_hpp
#define Server_hpp

#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <set>

using boost::asio::ip::tcp;

class Session;

class Server : public std::enable_shared_from_this<Server> {
	 public:
	Server(boost::asio::io_context& io_context, tcp::endpoint& endpoint);
	void accept();
	
	void join(std::shared_ptr<Session> session);
	void leave(std::shared_ptr<Session> session);
	
	void deliver(const std::string& msg);

	 private:
		tcp::acceptor acceptor_;
	std::set<std::shared_ptr<Session>> sessions_;
	
};

#endif /* Server_hpp */
