#include "LogManager.hpp"

std::ostream &operator<<(std::ostream &os, const LogMessage &message)
{
    os << message.ToString();
    return os;
}

LogManager::LogManager()
{
}

LogManager &LogManager::getInstance()
{
    static LogManager instance;
    return instance;
}

void LogManager::addObserver(EventType type, std::function<void(const LogMessage &)> observer)
{
    observers_[type].push_back(observer);
}

void LogManager::logMessage(EventType type, const LogMessage &message)
{
    for (auto &observer : observers_[type])
    {
        observer(message);
    }
}
