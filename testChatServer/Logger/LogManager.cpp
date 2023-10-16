#include "LogManager.hpp"

std::ostream &operator<<(std::ostream &os, const LogMessage &message)
{
    os << message.ToString();
    return os;
}

LogManager::LogManager()
{

    dbHandler_ = std::make_shared<DbHandler>();
    addObserver(LogManager::EventType::ChatEvent, ChatLogger(dbHandler_));
    //    addObserver(LogManager::EventType::ChatEvent, SocketBufferCheckLogger());
    addObserver(LogManager::EventType::ConnectionEvent, ConnectionLogger(dbHandler_));

    addObserver(LogManager::EventType::ErrorEvent, SystemLogger(dbHandler_));
}

LogManager &LogManager::getInstance()
{
    static LogManager instance;
    return instance;
}

void LogManager::addObserver(EventType type, std::function<void(const LogMessage &)> observer)
{
    observers_[type].push_back(std::move(observer));
}

void LogManager::logMessage(EventType type, const LogMessage &message)
{
    for (auto &observer : observers_[type])
    {
        observer(message);
    }
}

void LogManager::setDbHandler(std::shared_ptr<DbHandler> dbHandler)
{
    dbHandler_ = dbHandler;
}
