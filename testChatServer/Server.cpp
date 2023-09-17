// #include "Server.hpp"
// #include "Room.hpp"
// #include "Session.hpp"
//
// template <typename SrvComm, typename SesComm>
// Server<SrvComm, SesComm>::Server(boost::asio::io_context& io_context,
//										 tcp::endpoint&
// endpoint, std::shared_ptr<Room> room) 			:
// io_context_(io_context), room_(room), serverCommunicator_(
// std::make_shared<SrvComm>(io_context, endpoint)) {r
// co_spawn(io_context,
// accept(), detached);
// }
//
// template <typename SrvComm, typename SesComm>
// boost::asio::awaitable<void> Server<SrvComm, SesComm>::accept() {
//		for (;;) {
//				auto sessionCommunicator = co_await
// serverCommunicator_->asyncAccept();
//
//				try {
//						std::cout << "client accepted! "
//<<
// std::endl;
// std::make_shared<Session>(sessionCommunicator, room_)->start();
// }
// catch (std::exception& e) { std::cerr
// << "error in acception" << e.what() << std::endl;
//				}
//		}
// }
