#ifndef Session_hpp
#define Session_hpp

#include <boost/asio.hpp>
#include <boost/beast/websocket.hpp>
#include <cstdlib>
#include <iostream>
#include <queue>

#include "Room.hpp"
#include "ChatMessageWrapper.hpp"
#include "BaseSessionCommunicator.hpp"


using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::co_spawn;
using boost::asio::detached;
using boost::asio::use_awaitable;

template <typename SocketType>
class Session : public std::enable_shared_from_this<Session<SocketType>> {
	 public:
	Session(std::shared_ptr<BaseSessionCommunicator<SocketType>> communicator, std::shared_ptr<Room> room);
	void start();
	boost::asio::awaitable<void> readMsg();
	boost::asio::awaitable<void> startRead();

	void deliver(const ChatMessageWrapper& msg);
	boost::asio::awaitable<void> write();
	void stop();


	 private:
		std::shared_ptr<Room> room_;
		std::deque<ChatMessageWrapper> writeMsgs_;

		std::shared_ptr<BaseSessionCommunicator<SocketType>> communicator_;
};

template <typename SocketType>
Session<SocketType>::Session(std::shared_ptr<BaseSessionCommunicator<SocketType>> communicator,
														 std::shared_ptr<Room> room)
		: communicator_(communicator), room_(room) {}

template <typename SocketType>
void Session<SocketType>::start() {
		co_spawn(
				communicator_->getExecutor(),
				[self = this->shared_from_this()]() { return self->startRead(); }, detached);
		co_spawn(
				communicator_->getExecutor(),
				[self = this->shared_from_this()] { return self->write(); }, detached);
}

template <typename SocketType>
boost::asio::awaitable<void> Session<SocketType>::readMsg() {
		try {
				for (;;) {
						ChatMessageWrapper chatMessage =
								co_await communicator_->asyncRead();

						if (chatMessage.getDataType() == chat::TEXT) {
								room_->deliver(chatMessage);
								std::cout << "Message: " << chatMessage.getMessageText()
													<< std::endl;
						} else if (chatMessage.getDataType() == chat::IMAGE) {
								std::cout << " image" << std::endl;
						}
				}
		} catch (std::exception&) {
				stop();
		}
}

template <typename SocketType>
boost::asio::awaitable<void> Session<SocketType>::startRead() {
		try {
				room_->join(this->shared_from_this());
				co_await readMsg();
		} catch (std::exception&) {
				stop();
		}
}

template <typename SocketType>
void Session<SocketType>::deliver(const ChatMessageWrapper& msg) {
		writeMsgs_.push_back(msg);
		communicator_->cancelOne();
}

template <typename SocketType>
boost::asio::awaitable<void> Session<SocketType>::write() {
		try {
				for (;;) {
						if (writeMsgs_.empty()) {
								co_await communicator_->asyncWait();
						} else {
								auto sendBytes = writeMsgs_.front().encode();
								co_await communicator_->asyncWrite(sendBytes);
								writeMsgs_.pop_front();
						}
				}
		} catch (std::exception& e) {
				stop();
		}
}

template <typename SocketType>
void Session<SocketType>::stop() {
		room_->leave(this->shared_from_this());
		communicator_->stop();
}

#endif /* Session_hpp */
