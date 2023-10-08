#ifndef ChatLogger_hpp
#define ChatLogger_hpp

#include <functional>
#include <fstream>

#include "LogMessage.hpp"

class ChatLogger {
private:
		std::string buffer_;
		const std::string logFilePath_ = "chatLog.txt";
		const size_t maxBufferSize_ = 8192;

public:
		void operator()(const LogMessage& message) {
				buffer_ += message.ToString() + "\n";

				if (buffer_.size() >= maxBufferSize_) {
						std::ofstream logFile(logFilePath_, std::ios::app);
						logFile << buffer_;
						logFile.close();
						buffer_.clear();
				}
		}
};

#endif /* ChatLogger_hpp */
