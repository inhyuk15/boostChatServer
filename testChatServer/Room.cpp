#include "Room.hpp"

#include "ChatMessageWrapper.hpp"
#include "Session.hpp"

Room::Room()
{
}

void Room::join(std::shared_ptr<Session> session)
{
    //    std::cout << "session joined: " << std::endl;
    Sessions_.insert(session);
}

void Room::leave(std::shared_ptr<Session> session, const std::string &msg)
{
    //    std::cout << "session leaved: " << msg << std::endl;
    Sessions_.erase(session);
}

void Room::deliver(const ChatMessageWrapper &msg)
{
    for (auto session : Sessions_)
    {
        session->deliver(msg);
    }
}
