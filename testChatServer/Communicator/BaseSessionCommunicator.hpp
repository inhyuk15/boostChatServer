#ifndef BaseCommunicator_hpp
#define BaseCommunicator_hpp

#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::co_spawn;
using boost::asio::detached;
using boost::asio::use_awaitable;

class ChatMessageWrapper;

class BaseSessionCommunicator {

public:
	virtual ~BaseSessionCommunicator() = default;
	
	virtual tcp::socket::executor_type getExecutor() = 0;
	
	virtual boost::asio::awaitable<ChatMessageWrapper> asyncRead() = 0;
	
	virtual boost::asio::awaitable<void> asyncWrite(const std::string& sendBytes) = 0;
	
	virtual boost::asio::awaitable<void> asyncWait() = 0;
	
	virtual void cancelOne() = 0;
	
	virtual void stop() = 0;
	
protected:
	BaseSessionCommunicator(tcp::socket socket)
	: socket_(std::move(socket)), timer_(socket.get_executor()) {
		timer_.expires_at(std::chrono::steady_clock::time_point::max());
	}
	
	tcp::socket socket_;
	
	boost::asio::steady_timer timer_;
};

#endif /* BaseCommunicator_hpp */
