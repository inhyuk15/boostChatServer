#ifndef Session_hpp
#define Session_hpp

#include <boost/asio.hpp>
#include <boost/beast/websocket.hpp>
#include <cstdlib>
#include <iostream>
#include <queue>

#include "LogManager.hpp"
#include "Room.hpp"
#include "ChatMessageWrapper.hpp"
#include "BaseSessionCommunicator.hpp"

#include "LogManager.hpp"

using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::co_spawn;
using boost::asio::detached;
using boost::asio::use_awaitable;

class Session : public std::enable_shared_from_this<Session> {
	 public:
	Session(std::shared_ptr<BaseSessionCommunicator> communicator, std::shared_ptr<Room> room);
	void start();
	boost::asio::awaitable<void> readMsg();
	boost::asio::awaitable<void> startRead();

	void deliver(const ChatMessageWrapper& msg);
	boost::asio::awaitable<void> write();
	void stop(const std::string& msg);
	void stop(const ChatMessageWrapper& msg);


	 private:
		std::shared_ptr<Room> room_;
		std::deque<ChatMessageWrapper> writeMsgs_;
		std::shared_ptr<BaseSessionCommunicator> communicator_;
	
		std::atomic<bool> connected_{false};
	
		static constexpr char TIMEOUT[] = "timeout";
};

#endif /* Session_hpp */
