#ifndef Session_hpp
#define Session_hpp

#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <queue>

#include "ChatMessageWrapper.hpp"

using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::co_spawn;
using boost::asio::detached;
using boost::asio::use_awaitable;

class BaseSessionCommunicator;
class Room;

class Session : public std::enable_shared_from_this<Session> {
	 public:
	Session(std::shared_ptr<BaseSessionCommunicator> communicator, std::shared_ptr<Room> room);
	void start();
	boost::asio::awaitable<void> readMsg();
	boost::asio::awaitable<void> startRead();
	
	void deliver(const ChatMessageWrapper& msg);
	boost::asio::awaitable<void> write();
	void stop();
	
	std::string nickname();
	
	 private:
		std::shared_ptr<Room> room_;
		
		std::deque<std::string> writeMsgs_;
		std::deque<ChatMessageWrapper> writeMsgs2_;
		std::string nickname_;
		
		std::shared_ptr<BaseSessionCommunicator> communicator_;
};

#endif /* Session_hpp */
