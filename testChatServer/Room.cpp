#include "Room.hpp"

#include "ChatMessageWrapper.hpp"
#include "Session.hpp"

Room::Room() {}

void Room::join(std::shared_ptr<Session> session) {
    std::cout << "session joined: " << std::endl;
    Sessions_.insert(session);
}

// void Room::join(std::shared_ptr<Session<WsSocketType>> session) {
//     std::cout << "session joined: " << std::endl;
//     wsSessions_.insert(session);
// }

void Room::leave(std::shared_ptr<Session> session) {
    std::cout << "session leaved: " << std::endl;
    Sessions_.erase(session);
}

// void Room::leave(std::shared_ptr<Session<WsSocketType>> session) {
//     std::cout << "session leaved: " << std::endl;
//     wsSessions_.erase(session);
// }

void Room::deliver(const ChatMessageWrapper& msg) {
    for (auto session : Sessions_) {
        session->deliver(msg);
    }
    //    for (auto session : wsSessions_) {
    //        session->deliver(msg);
    //    }
}
