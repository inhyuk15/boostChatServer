#include "TcpServer.hpp"

#include "Room.hpp"
#include "Session.hpp"
#include "TcpServerCommunicator.hpp"
#include "TcpSessionCommunicator.hpp"

TcpServer::TcpServer(boost::asio::io_context& io_context,
                     tcp::endpoint& endpoint)
    : Server(io_context, endpoint),
      serverCommunicator_(
          std::make_shared<TcpServerCommunicator>(io_context, endpoint)) {
    room_ = std::make_shared<Room>();

    co_spawn(io_context, accept(), detached);
}

boost::asio::awaitable<void> TcpServer::accept() {
    for (;;) {
        auto sessionCommunicator = co_await serverCommunicator_->asyncAccept();

        try {
            std::cout << "client accepted! " << std::endl;
            std::make_shared<Session>(sessionCommunicator, room_)->start();
        } catch (std::exception& e) {
            std::cerr << "error in acception" << e.what() << std::endl;
        }
    }
}
