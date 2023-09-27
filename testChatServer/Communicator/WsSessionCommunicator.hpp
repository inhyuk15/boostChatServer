#ifndef WsSessionCommunicator_hpp
#define WsSessionCommunicator_hpp

#include <boost/asio.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include "BaseSessionCommunicator.hpp"

using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::co_spawn;
using boost::asio::detached;
using boost::asio::use_awaitable;

using WsSocketType = boost::beast::websocket::stream<boost::beast::tcp_stream>;

class ChatMessageWrapper;

class WsSessionCommunicator : public BaseSessionCommunicator {
public:
	WsSessionCommunicator(WsSocketType socket);
	boost::asio::any_io_executor getExecutor() override;

private:
	boost::asio::awaitable<ChatMessageWrapper> asyncRead() override;

	boost::asio::awaitable<void> asyncWrite(const std::string& sendBytes) override;

	boost::asio::awaitable<void> asyncWait() override;

	void cancelOne() override;

	void stop() override;
	
	WsSocketType socket_;
	boost::asio::steady_timer timer_;
};

#endif /* WsSessionCommunicator_hpp */
