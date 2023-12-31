#ifndef Room_hpp
#define Room_hpp

#include <boost/asio.hpp>
#include <boost/beast/websocket.hpp>
#include <cstdlib>
#include <iostream>
#include <set>

using boost::asio::ip::tcp;

class Session;

class ChatMessageWrapper;

class Room {
public:
	Room();
	
	void join(std::shared_ptr<Session> session);
	
	void leave(std::shared_ptr<Session> session, const std::string& msg);
	
	void deliver(const ChatMessageWrapper& msg);
	
private:
	std::set<std::shared_ptr<Session>> Sessions_;
};

#endif /* Room_hpp */
