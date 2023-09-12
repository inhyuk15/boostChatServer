#ifndef BaseServerCommunicator_hpp
#define BaseServerCommunicator_hpp


#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::co_spawn;
using boost::asio::detached;
using boost::asio::use_awaitable;

class BaseSessionCommunicator;

class BaseServerCommunicator {
public:
	virtual ~BaseServerCommunicator() = default;
	virtual boost::asio::awaitable<std::shared_ptr<BaseSessionCommunicator>> asyncAccept() = 0;
	
protected:
	BaseServerCommunicator(boost::asio::io_context& io_context, tcp::endpoint& endpoint): io_context_(io_context), acceptor_(io_context, endpoint) {}
	
	boost::asio::io_context& io_context_;
	tcp::acceptor acceptor_;
};


#endif /* BaseServerCommunicator_hpp */
