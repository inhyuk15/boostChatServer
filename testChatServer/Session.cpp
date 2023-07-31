//
//  Session.cpp
//  testChatServer
//
//  Created by inhyuk on 2023/07/31.
//

#include "Session.hpp"

Session::Session(tcp::socket socket)
    : socket_(std::move(socket)), buff_(BUFF_SIZE) {}
void Session::start() { read(); }

void Session::read() {
    auto self(shared_from_this());
    boost::asio::async_read_until(
        socket_, buff_, '\n',
        [this, self](boost::system::error_code ec, size_t bytesRead) {
            if (!ec) {
                std::istream is(&buff_);
                std::string line;
                std::getline(is, line);

                std::cout << "read success : " << line << std::endl;
                read();
            } else {
                std::cerr << "error in reading " << ec.message() << std::endl;
                socket_.close();
            }
        });
}
