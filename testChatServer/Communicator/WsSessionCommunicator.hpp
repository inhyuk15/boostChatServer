//#ifndef WsSessionCommunicator_hpp
//#define WsSessionCommunicator_hpp
//
//#include <boost/asio.hpp>
//#include "BaseSessionCommunicator.hpp"
//
//using boost::asio::ip::tcp;
//using boost::asio::awaitable;
//using boost::asio::co_spawn;
//using boost::asio::detached;
//using boost::asio::use_awaitable;
//
//using WsSocketType = boost::beast::websocket::stream<tcp::socket>;
//
//class ChatMessageWrapper;
//
//class WsSessionCommunicator : public BaseSessionCommunicator<WsSocketType> {
//public:
//	WsSessionCommunicator(WsSocketType socket);
//	tcp::socket::executor_type getExecutor() override;
//
//private:
//	boost::asio::awaitable<ChatMessageWrapper> asyncRead() override;
//
//	boost::asio::awaitable<void> asyncWrite(const std::string& sendBytes) override;
//
//	boost::asio::awaitable<void> asyncWait() override;
//
//	void cancelOne() override;
//
//	void stop() override;
//};
//
//#endif /* WsSessionCommunicator_hpp */
