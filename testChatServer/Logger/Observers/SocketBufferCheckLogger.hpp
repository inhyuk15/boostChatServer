//
//  BufferCheckLogger.hpp
//  testChatServer
//
//  Created by inhyuk on 2023/10/09.
//

#ifndef BufferCheckLogger_hpp
#define BufferCheckLogger_hpp

#include <iostream>

class SocketBufferCheckLogger {

public:
		void operator()(const LogMessage &message) {
			std::cout << message << std::endl;
		}
};

#endif /* BufferCheckLogger_hpp */
