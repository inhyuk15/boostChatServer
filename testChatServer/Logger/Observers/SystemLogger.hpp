#ifndef SystemLogger_hpp
#define SystemLogger_hpp

#include <functional>
#include <fstream>

#include "LogMessage.hpp"

class SystemLogger {
private:
	std::vector<LogMessage> buffer_;
	const size_t maxBufferSize_ = 1024;
	size_t curBufferSize_;
	const size_t maxMsgCnt_ = 50;
	size_t curMsgCnt_;
	std::shared_ptr<DbHandler> dbHandler_;

public:
		SystemLogger(std::shared_ptr<DbHandler> dbHandler)
		: dbHandler_(dbHandler), curBufferSize_(0), curMsgCnt_(0) {}

		void operator()(const LogMessage &message) {
				buffer_.push_back(message);
				curBufferSize_ += message.ToString().length();
				curMsgCnt_++;
		
				if (curBufferSize_ >= maxBufferSize_ || curMsgCnt_ > maxMsgCnt_) {
					dbHandler_->storeLogMessage(buffer_);
					buffer_.clear();
					curBufferSize_ = 0;
					curMsgCnt_ = 0;
				}
		}
};
#endif /* SystemLogger_hpp */
