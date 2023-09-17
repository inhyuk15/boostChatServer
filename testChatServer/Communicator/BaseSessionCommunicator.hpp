#ifndef BaseCommunicator_hpp
#define BaseCommunicator_hpp

#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::co_spawn;
using boost::asio::detached;
using boost::asio::use_awaitable;

class ChatMessageWrapper;

template <typename SocketType>
class BaseSessionCommunicator {
public:
	virtual ~BaseSessionCommunicator() = default;
	
	virtual boost::asio::any_io_executor getExecutor() = 0;
	
	virtual boost::asio::awaitable<ChatMessageWrapper> asyncRead() = 0;
	
	virtual boost::asio::awaitable<void> asyncWrite(const std::string& sendBytes) = 0;
	
	virtual boost::asio::awaitable<void> asyncWait() = 0;
	
	virtual void cancelOne() = 0;
	
	virtual void stop() = 0;
	
protected:
	BaseSessionCommunicator(SocketType socket): socket_(std::move(socket)), timer_(socket.get_executor()) {}
	tcp::socket socket_;
	boost::asio::steady_timer timer_;
};

#endif /* BaseCommunicator_hpp */
