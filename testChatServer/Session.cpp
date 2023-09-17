// #include "Session.hpp"
//
// #include "BaseSessionCommunicator.hpp"
// #include "Room.hpp"
//
// Session::Session(std::shared_ptr<BaseSessionCommunicator> communicator,
//                  std::shared_ptr<Room> room)
//     : communicator_(communicator), room_(room) {}
//
// void Session::start() {
//     co_spawn(
//         communicator_->getExecutor(),
//         [self = shared_from_this()]() { return self->startRead(); },
//         detached);
//     co_spawn(
//         communicator_->getExecutor(),
//         [self = shared_from_this()] { return self->write(); }, detached);
// }
//
// boost::asio::awaitable<void> Session::readMsg() {
//     try {
//         for (;;) {
//             ChatMessageWrapper chatMessage =
//                 co_await communicator_->asyncRead();
//
//             if (chatMessage.getDataType() == chat::TEXT) {
//                 room_->deliver(chatMessage);
//                 std::cout << "Message: " << chatMessage.getMessageText()
//                           << std::endl;
//             } else if (chatMessage.getDataType() == chat::IMAGE) {
//                 std::cout << " image" << std::endl;
//             }
//         }
//     } catch (std::exception&) {
//         stop();
//     }
// }
//
// boost::asio::awaitable<void> Session::startRead() {
//     try {
//         room_->join(shared_from_this());
//         co_await readMsg();
//     } catch (std::exception&) {
//         stop();
//     }
// }
//
// void Session::deliver(const ChatMessageWrapper& msg) {
//     writeMsgs2_.push_back(msg);
//     communicator_->cancelOne();
// }
//
// boost::asio::awaitable<void> Session::write() {
//     try {
//         for (;;) {
//             if (writeMsgs2_.empty()) {
//                 co_await communicator_->asyncWait();
//             } else {
//                 auto sendBytes = writeMsgs2_.front().encode();
//                 co_await communicator_->asyncWrite(sendBytes);
//                 writeMsgs2_.pop_front();
//             }
//         }
//     } catch (std::exception& e) {
//         stop();
//     }
// }
//
// void Session::stop() {
//     room_->leave(shared_from_this());
//     communicator_->stop();
// }
//
// std::string Session::nickname() { return nickname_; }
