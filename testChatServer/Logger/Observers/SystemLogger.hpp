#ifndef SystemLogger_hpp
#define SystemLogger_hpp

#include <functional>
#include <fstream>

#include "LogMessage.hpp"

class SystemLogger {
private:
		std::string buffer_;
		const std::string logFilePath_ = "systemLog.txt";
		const size_t maxBufferSize_ = 1024;

public:
		void operator()(const LogMessage &message) {
				buffer_ += message.ToString() + "\n";

				if (buffer_.size() >= maxBufferSize_) {
						std::ofstream logFile(logFilePath_, std::ios::app);
						logFile << buffer_;
						logFile.close();
						buffer_.clear();
				}
		}
};
#endif /* SystemLogger_hpp */
