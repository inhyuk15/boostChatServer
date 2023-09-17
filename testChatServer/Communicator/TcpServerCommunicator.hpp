#ifndef TcpServerCommunicator_hpp
#define TcpServerCommunicator_hpp

#include "BaseServerCommunicator.hpp"

class TcpSessionCommunicator;

class TcpServerCommunicator : public BaseServerCommunicator<TcpSessionCommunicator> {
//class TcpServerCommunicator {
public:
	TcpServerCommunicator(boost::asio::io_context& io_context, const tcp::endpoint& endpoint);
	boost::asio::awaitable<std::shared_ptr<TcpSessionCommunicator>> asyncAccept() override;
//		boost::asio::awaitable<std::shared_ptr<TcpSessionCommunicator>> asyncAccept();
};

#endif /* TcpServerCommunicator_hpp */
