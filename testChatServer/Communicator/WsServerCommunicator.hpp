//#ifndef WebSocketCommunicator_hpp
//#define WebSocketCommunicator_hpp
//
//#include <boost/beast/core.hpp>
//#include <boost/beast/websocket.hpp>
//
//#include "BaseServerCommunicator.hpp"
//
//using namespace boost::beast;
//using namespace boost::beast::websocket;
//
//class BaseSessionCommunicator;
//
//class WsServerCommunicator : public BaseServerCommunicator {
//public:
//	WsServerCommunicator(boost::asio::io_context& io_context, tcp::endpoint& endpoint);
//	
//	boost::asio::awaitable<std::shared_ptr<BaseSessionCommunicator>> asyncAccept() override;
//	
//	boost::asio::awaitable<void> handshake();
//};
//
//#endif /* WebSocketCommunicator_hpp */
