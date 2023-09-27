#ifndef BaseCommunicator_hpp
#define BaseCommunicator_hpp

#include <boost/asio.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <iostream>

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
};


#endif /* BaseCommunicator_hpp */
