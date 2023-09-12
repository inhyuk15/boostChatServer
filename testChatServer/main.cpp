#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>

#include "Server.hpp"
#include "Session.hpp"
#include "TcpServer.hpp"
#include "WebSocketServer.hpp"

using boost::asio::ip::tcp;

int main(int argc, const char* argv[]) {
    std::string tcpPort = "4000";
    std::string wsPort = "4001";
    boost::asio::io_context io_context;
    tcp::endpoint tcpEndpoint(tcp::v4(), stoi(tcpPort));
    tcp::endpoint wsEndpoint(tcp::v4(), stoi(wsPort));
    try {
        std::shared_ptr<Server> tcpServer =
            std::make_shared<TcpServer>(io_context, tcpEndpoint);

        //        std::shared_ptr<Server> webSocketServer =
        //            std::make_shared<WebSocketServer>(io_context, wsEndpoint);

        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception in main " << e.what() << std::endl;
    }

    return 0;
}
