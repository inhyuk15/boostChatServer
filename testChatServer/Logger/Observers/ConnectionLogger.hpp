#ifndef ConnectionLogger_hpp
#define ConnectionLogger_hpp

#include <functional>
#include <fstream>

#include "LogMessage.hpp"

class ConnectionLogger {
private:
		std::string buffer_;
		const std::string logFilePath_ = "connectionLog.txt";
		const size_t maxBufferSize_ = 1024;

public:
		void operator()(const LogMessage &message) {
				buffer_ += message.ToString() + "\n";

				// 연결 관련 로그 처리
				LogMessage::ConnectionState connectionState = message.getConnectionState();
				if (connectionState == LogMessage::ConnectionState::Connected)
				{
						
				}
				else if (connectionState == LogMessage::ConnectionState::Disconnected)
				{
						
				}
				else if (connectionState == LogMessage::ConnectionState::Reconnected)
				{
				}
				std::cout << message << std::endl;
		
				if (buffer_.size() >= maxBufferSize_) {
						std::ofstream logFile(logFilePath_, std::ios::app);
						logFile << buffer_;
						logFile.close();
						buffer_.clear();
				}
		}
};

#endif /* ConnectionLogger_hpp */
