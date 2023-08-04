#include "Server.hpp"

#include "Session.hpp"

Server::Server(boost::asio::io_context& io_context, tcp::endpoint& endpoint)
    : acceptor_(io_context, endpoint) {}
void Server::accept() {
    auto self(shared_from_this());
    acceptor_.async_accept(
        [this, self](boost::system::error_code ec, tcp::socket socket) {
            if (!ec) {
                std::cout << "client accepted! " << std::endl;
                std::make_shared<Session>(std::move(socket), self)->start();
            } else {
                std::cerr << "error in acception" << ec.message() << std::endl;
            }
            accept();
        });
}

void Server::join(std::shared_ptr<Session> session) {
    std::cout << "session joined" << std::endl;
    sessions_.insert(session);
}

void Server::leave(std::shared_ptr<Session> session) {
    std::cout << "session leaved" << std::endl;
    sessions_.erase(session);
}

void Server::deliver(const std::string& msg) {
    for (auto session : sessions_) {
        session->deliver(msg);
    }
}
