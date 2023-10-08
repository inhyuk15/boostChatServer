#ifndef LogManager_hpp
#define LogManager_hpp

#include <map>
#include <list>
#include <iostream>
#include <sstream>

#include "LogMessage.hpp"
#include "ChatLogger.hpp"
#include "ConnectionLogger.hpp"
#include "SystemLogger.hpp"

//class ConnectionLogger;
//class SystemLogger;
class ChatMessageWrapper;
class LogMessage;

class LogManager {
public:
		enum class EventType { ChatEvent, ConnectionEvent, ErrorEvent };

		static LogManager& getInstance();
		
		void addObserver(EventType type, std::function<void(const LogMessage&)> observer);
		void logMessage(EventType type, const LogMessage& message);
private:
	LogManager();
		std::map<EventType, std::list<std::function<void(const LogMessage&)>>> observers_;
};

#endif /* LogManager_hpp */
