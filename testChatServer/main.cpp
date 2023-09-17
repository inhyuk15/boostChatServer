#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>

#include "Room.hpp"
#include "Server.hpp"
// #include "Session.hpp"
// #include "TcpServer.hpp"
//  #include "WsServer.hpp"
#include "TcpServerCommunicator.hpp"
#include "TcpSessionCommunicator.hpp"

using boost::asio::ip::tcp;
// using TcpServer = Server<tcp::socket>;
// using TcpServer = Server<TcpServerCommunicator, tcp::socket>;
using TcpServer =
    Server<TcpServerCommunicator, TcpSessionCommunicator, tcp::socket>;

int main(int argc, const char* argv[]) {
    std::string tcpPort = "4000";
    //    std::string wsPort = "4001";
    boost::asio::io_context io_context;
    tcp::endpoint tcpEndpoint(tcp::v4(), stoi(tcpPort));
    //    tcp::endpoint wsEndpoint(tcp::v4(), stoi(wsPort));
    try {
        auto room = std::make_shared<Room>();
        auto server =
            std::make_shared<TcpServer>(io_context, tcpEndpoint, room);

        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception in main " << e.what() << std::endl;
    }

    return 0;
}
