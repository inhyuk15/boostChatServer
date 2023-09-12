#include "Room.hpp"

#include "ChatMessageWrapper.hpp"
#include "Session.hpp"

Room::Room() {}

void Room::join(std::shared_ptr<Session> session) {
    std::cout << "session joined: " << session->nickname() << std::endl;
    sessions_.insert(session);
}

void Room::leave(std::shared_ptr<Session> session) {
    std::cout << "session leaved: " << session->nickname() << std::endl;
    sessions_.erase(session);
}

void Room::deliver(const ChatMessageWrapper& msg) {
    for (auto session : sessions_) {
        session->deliver(msg);
    }
}
