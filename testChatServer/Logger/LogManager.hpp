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
#include "SocketBufferCheckLogger.hpp"

class ChatMessageWrapper;
class LogMessage;

class DbHandler;

class LogManager {
public:
		enum class EventType { ChatEvent, ConnectionEvent, ErrorEvent };

		static LogManager& getInstance();
		
		void addObserver(EventType type, std::function<void(const LogMessage&)> observer);
		void logMessage(EventType type, const LogMessage& message);
	
	void setDbHandler(std::shared_ptr<DbHandler>);
private:
		LogManager();
		std::map<EventType, std::list<std::function<void(const LogMessage&)>>> observers_;
	
		std::shared_ptr<DbHandler> dbHandler_;
};

#endif /* LogManager_hpp */
