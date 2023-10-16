#ifndef DbHandler_hpp
#define DbHandler_hpp

#include <iostream>
#include <hiredis/hiredis.h>
#include "LogMessage.hpp"

class DbHandler {
private:
		redisContext *context_;
		const char *hostname_ = "127.0.0.1";
		int port_ = 6379;

public:
	DbHandler();
	
	~DbHandler();
	
	void storeLogMessage(const std::vector<LogMessage>& logMessage);
};

#endif /* DbHandler_hpp */
