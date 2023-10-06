#ifndef LogManger_hpp
#define LogManger_hpp

#include <map>
#include <list>

class LogMessage {
public:
		LogMessage(const std::string& content)
				: content_(content) {}
		const std::string& getContent() const { return content_; }

private:
		std::string content_;
};


class LogManager {
public:
		enum EventType { ChatEvent, ConnectionEvent, ErrorEvent };

		static LogManager& getInstance() {
				static LogManager instance;
				return instance;
		}

		void addObserver(EventType type, std::function<void(const LogMessage&)> observer) {
				observers_[type].push_back(observer);
		}

		void logMessage(EventType type, const LogMessage& message) {
				for (auto& observer : observers_[type]) {
						observer(message);
				}
		}

private:
		LogManager() {}
		std::map<EventType, std::list<std::function<void(const LogMessage&)>>> observers_;
};

#endif /* LogManger_hpp */
