#include "Room.hpp"

#include "ChatMessageWrapper.hpp"
#include "Session.hpp"

Room::Room() {}

void Room::join(std::shared_ptr<Session<tcp::socket>> session) {
    std::cout << "session joined: " << std::endl;
    tcpSessions_.insert(session);
}

void Room::join(std::shared_ptr<Session<WsSocketType>> session) {
    std::cout << "session joined: " << std::endl;
    wsSessions_.insert(session);
}

void Room::leave(std::shared_ptr<Session<tcp::socket>> session) {
    std::cout << "session leaved: " << std::endl;
    tcpSessions_.erase(session);
}

void Room::leave(std::shared_ptr<Session<WsSocketType>> session) {
    std::cout << "session leaved: " << std::endl;
    wsSessions_.erase(session);
}

void Room::deliver(const ChatMessageWrapper& msg) {
    for (auto session : tcpSessions_) {
        session->deliver(msg);
    }
}
