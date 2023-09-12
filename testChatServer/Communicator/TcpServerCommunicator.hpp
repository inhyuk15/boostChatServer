#ifndef TcpServerCommunicator_hpp
#define TcpServerCommunicator_hpp

#include "BaseServerCommunicator.hpp"

class BaseSessionCommunicator;

class TcpServerCommunicator : public BaseServerCommunicator {
public:
	TcpServerCommunicator(boost::asio::io_context& io_context, tcp::endpoint& endpoint);
	boost::asio::awaitable<std::shared_ptr<BaseSessionCommunicator>> asyncAccept() override;
};

#endif /* TcpServerCommunicator_hpp */
