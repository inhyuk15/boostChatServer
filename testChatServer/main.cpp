#include <boost/asio.hpp>
#include <boost/beast/websocket.hpp>
#include <cstdlib>
#include <iostream>

#include "Room.hpp"
#include "Server.hpp"
#include "TcpServerCommunicator.hpp"
#include "TcpSessionCommunicator.hpp"
#include "WsServerCommunicator.hpp"
#include "WsSessionCommunicator.hpp"

using boost::asio::ip::tcp;
using TcpServer =
    Server<TcpServerCommunicator, TcpSessionCommunicator, tcp::socket>;
using WsServer = Server<WsServerCommunicator, WsSessionCommunicator,
                        boost::beast::websocket::stream<tcp::socket>>;

int main(int argc, const char* argv[]) {
    std::string tcpPort = "4000";
    std::string wsPort = "4001";

    boost::asio::io_context io_context;

    tcp::endpoint tcpEndpoint(tcp::v4(), stoi(tcpPort));
    tcp::endpoint wsEndpoint(tcp::v4(), stoi(wsPort));

    try {
        auto room = std::make_shared<Room>();
        auto tcpServer =
            std::make_shared<TcpServer>(io_context, tcpEndpoint, room);
        //        auto wsServer =
        //            std::make_shared<WsServer>(io_context, wsEndpoint, room);
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception in main " << e.what() << std::endl;
    }

    return 0;
}
