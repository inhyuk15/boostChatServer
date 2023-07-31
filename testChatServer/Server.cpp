//
//  Server.cpp
//  testChatServer
//
//  Created by inhyuk on 2023/07/31.
//

#include "Server.hpp"

Server::Server(boost::asio::io_context& io_context, tcp::endpoint& endpoint)
    : acceptor_(io_context, endpoint) {
    accept();
}
void Server::accept() {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket) {
            if (!ec) {
                std::cout << "client accepted! " << std::endl;
                std::make_shared<Session>(std::move(socket))->start();
            } else {
                std::cerr << "error in acception" << ec.message() << std::endl;
            }
            accept();
        });
}
