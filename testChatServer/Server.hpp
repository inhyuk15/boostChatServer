#ifndef Server_hpp
#define Server_hpp

#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <set>
#include "Room.hpp"
#include "Session.hpp"

using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::co_spawn;
using boost::asio::detached;
using boost::asio::use_awaitable;


template <typename SrvComm, typename SesComm>
class Server : public std::enable_shared_from_this<Server<SrvComm, SesComm>> {
public:
	Server(boost::asio::io_context& io_context, const tcp::endpoint& endpoint, std::shared_ptr<Room> room);
	boost::asio::awaitable<void> accept();

private:
	boost::asio::io_context& io_context_;
	std::shared_ptr<Room> room_;
	std::shared_ptr<SrvComm> serverCommunicator_;
};

template <typename SrvComm, typename SesComm>
Server<SrvComm, SesComm>::Server(boost::asio::io_context& io_context,
										 const tcp::endpoint& endpoint, std::shared_ptr<Room> room)
: io_context_(io_context), room_(room)
, serverCommunicator_(
					std::make_shared<SrvComm>(io_context, endpoint)) {
		co_spawn(io_context, accept(), detached);
}

template <typename SrvComm, typename SesComm>
boost::asio::awaitable<void> Server<SrvComm, SesComm>::accept() {
	for (;;) {
		auto sessionCommunicator = co_await serverCommunicator_->asyncAccept();
		try {
			std::make_shared<Session>(sessionCommunicator, room_)->start();
		} catch (std::exception& e) {
			std::cerr << "error in acception" << e.what() << std::endl;
		}
	}
}

#endif
