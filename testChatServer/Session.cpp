#include "Session.hpp"

#include "Util.hpp"

Session::Session(std::shared_ptr<BaseSessionCommunicator> communicator, std::shared_ptr<Room> room)
    : communicator_(communicator), room_(room)
{
}

void Session::start()
{
    co_spawn(
        communicator_->getExecutor(), [self = this->shared_from_this()]() { return self->startRead(); }, detached);
    co_spawn(
        communicator_->getExecutor(), [self = this->shared_from_this()] { return self->write(); }, detached);
}

boost::asio::awaitable<void> Session::readMsg()
{
    try
    {
        if (!connected_.load())
        {
            co_return;
        }
        for (;;)
        {
            if (!connected_.load())
            {
                break;
            }
            ChatMessageWrapper chatMessage = co_await communicator_->asyncRead();
            // encode base64 for test
            //            std::cout << "raw data:" << chatMessage.Base64Encode(chatMessage.encode()) << std::endl;
            std::string timestamp = convertUint32ToString(chatMessage.getTimestamp());
            if (chatMessage.getDataType() == chat::TEXT)
            {
                room_->deliver(chatMessage);
                LogMessage logMessage(chatMessage);
                LogManager::getInstance().logMessage(LogManager::EventType::ChatEvent, logMessage);
            }
            else if (chatMessage.getDataType() == chat::IMAGE)
            {
                // 임시로 둠, 이미지의 식별자를 전달할 예정
                LogMessage logMessage(timestamp, "Image identifier-0x3f3f3f3f");
                LogManager::getInstance().logMessage(LogManager::EventType::ChatEvent, logMessage);
            }
            else if (chatMessage.getDataType() == chat::SYSTEM)
            {
                if (chatMessage.getSystemCode() == chat::TIMEOUT)
                {
                    stop(TIMEOUT);
                }
            }
        }
    }
    catch (std::exception &e)
    {
        stop(e.what());
    }
}

boost::asio::awaitable<void> Session::startRead()
{
    try
    {
        room_->join(this->shared_from_this());
        connected_.store(true);
        co_await readMsg();
    }
    catch (std::exception &e)
    {
        stop(e.what());
    }
}

void Session::deliver(const ChatMessageWrapper &msg)
{
    writeMsgs_.push_back(msg);
    communicator_->cancelOne();
}

boost::asio::awaitable<void> Session::write()
{
    try
    {
        if (!connected_.load())
        {
            co_return;
        }
        for (;;)
        {
            if (!connected_.load())
            {
                break;
            }
            if (writeMsgs_.empty())
            {
                co_await communicator_->asyncWait();
            }
            else
            {
                auto sendBytes = writeMsgs_.front().encode();
                co_await communicator_->asyncWrite(sendBytes);
                writeMsgs_.pop_front();
            }
        }
    }
    catch (std::exception &e)
    {
        stop(e.what());
    }
}

// error
void Session::stop(const std::string &msg)
{
    std::string timestamp = convertUint32ToString(getCurTimestamp());
    LogMessage logMsg(timestamp, msg);
    LogManager::getInstance().logMessage(LogManager::EventType::ErrorEvent, logMsg);

    room_->leave(this->shared_from_this(), msg);
    communicator_->stop();
    connected_.store(false);
}

// disconnect by client or timeout
void Session::stop(const ChatMessageWrapper &chatMessage)
{
    LogMessage logMsg(chatMessage);
    LogManager::getInstance().logMessage(LogManager::EventType::ConnectionEvent, logMsg);

    room_->leave(this->shared_from_this(), "disconnect");
    communicator_->stop();
    connected_.store(false);
}
