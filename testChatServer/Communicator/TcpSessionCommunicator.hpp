#ifndef TcpSessionCommunicator_hpp
#define TcpSessionCommunicator_hpp

#include <boost/asio.hpp>
#include "BaseSessionCommunicator.hpp"

using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::co_spawn;
using boost::asio::detached;
using boost::asio::use_awaitable;

class ChatMessageWrapper;

class TcpSessionCommunicator : public BaseSessionCommunicator {
public:
	TcpSessionCommunicator(tcp::socket socket);

	tcp::socket::executor_type getExecutor() override;
	
private:
	boost::asio::awaitable<ChatMessageWrapper> asyncRead() override;
	
	boost::asio::awaitable<void> asyncWrite(const std::string& sendBytes) override;
	
	boost::asio::awaitable<void> asyncWait() override;
	
	void cancelOne() override;
	
	void stop() override;
};

#endif /* TcpSessionCommunicator_hpp */
