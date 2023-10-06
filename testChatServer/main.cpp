#include <boost/asio.hpp>
#include <boost/beast/websocket.hpp>
#include <cstdlib>
#include <iostream>

#include "LogManager.hpp"
#include "Room.hpp"
#include "Server.hpp"
#include "TcpServerCommunicator.hpp"
#include "TcpSessionCommunicator.hpp"
#include "WsServerCommunicator.hpp"
#include "WsSessionCommunicator.hpp"

using boost::asio::ip::tcp;
using TcpServer = Server<TcpServerCommunicator, TcpSessionCommunicator>;
using WsServer = Server<WsServerCommunicator, WsSessionCommunicator>;

int main(int argc, const char* argv[]) {
    std::string tcpPort = "4000";
    std::string wsPort = "4001";

    boost::asio::io_context io_context;

    tcp::endpoint tcpEndpoint(tcp::v4(), stoi(tcpPort));
    tcp::endpoint wsEndpoint(tcp::v4(), stoi(wsPort));
    LogManager& logManager = LogManager::getInstance();
    logManager.addObserver(LogManager::EventType::ChatEvent,
                           [](const LogMessage& message) {
                               // 채팅 관련 로그 처리
                               std::cout << message.getContent() << std::endl;
                           });

    logManager.addObserver(LogManager::EventType::ConnectionEvent,
                           [](const LogMessage& message) {
                               // 연결 관련 로그 처리
                               std::cout << message.getContent() << std::endl;
                           });

    logManager.addObserver(LogManager::EventType::ErrorEvent,
                           [](const LogMessage& message) {
                               // 오류 관련 로그 처리
                               std::cout << message.getContent() << std::endl;
                           });

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
