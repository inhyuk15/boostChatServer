#ifndef Room_hpp
#define Room_hpp

#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <set>

using boost::asio::ip::tcp;

template <typename SocketType>
class Session;

class ChatMessageWrapper;

class Room {
public:
	Room();
	
	void join(std::shared_ptr<Session<tcp::socket>> session);
	
	void leave(std::shared_ptr<Session<tcp::socket>> session);
	
	void deliver(const ChatMessageWrapper& msg);
	
private:
	std::set<std::shared_ptr<Session<tcp::socket>>> tcpSessions_;
//	std::set<std::shared_ptr<Session<websocket::stream>> wsSessions_;
};

#endif /* Room_hpp */
