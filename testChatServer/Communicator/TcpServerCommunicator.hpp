#ifndef TcpServerCommunicator_hpp
#define TcpServerCommunicator_hpp

#include <iostream>
#include "BaseServerCommunicator.hpp"

class TcpSessionCommunicator;

class TcpServerCommunicator : public BaseServerCommunicator<TcpSessionCommunicator> {
public:
	TcpServerCommunicator(boost::asio::io_context& io_context, const tcp::endpoint& endpoint);
	boost::asio::awaitable<std::shared_ptr<TcpSessionCommunicator>> asyncAccept() override;
};

#endif /* TcpServerCommunicator_hpp */
