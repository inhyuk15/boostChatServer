#ifndef Session_hpp
#define Session_hpp

#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
	 public:
	Session(tcp::socket socket);
	void start();
	void read();

	 private:
		tcp::socket socket_;
		boost::asio::streambuf buff_;
		static constexpr int BUFF_SIZE = 32;
};

#endif /* Session_hpp */
