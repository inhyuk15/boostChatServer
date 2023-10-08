//
//  LogMessage.hpp
//  testChatServer
//
//  Created by inhyuk on 2023/10/08.
//

#ifndef LogMessage_hpp
#define LogMessage_hpp

#include <sstream>

#include "Util.hpp"
#include "ChatMessageWrapper.hpp"

class LogMessage {
public:
		enum class ConnectionState { Connected, Disconnected, Reconnected, None };
		LogMessage() {}
		LogMessage(std::string timestamp, const std::string& content,
							 ConnectionState state = ConnectionState::None, const std::string& usrIdentity = "none")
				: timestamp_(timestamp), content_(content), state_(state), usrIdentity_(usrIdentity) {}
		LogMessage(const ChatMessageWrapper& chatMessage) {
			timestamp_ = convertUint32ToString(chatMessage.getTimestamp());
			content_ = chatMessage.getMessageText();
			// reconnect 인지 아닌지는 client에서 보내야함. 이건 추후 수정 필요, 일단 Connected로 둠
			state_ = ConnectionState::Connected;
			usrIdentity_ = chatMessage.getUserName();
		}
	
		std::string ToString() const {
			std::stringstream ss;
			
			ss << timestamp_ << ":" << usrIdentity_ << ":" << static_cast<int>(state_) << ":" << content_;
			return ss.str();
		}
		
		friend std::ostream& operator<<(std::ostream& os, const LogMessage& message);

		void setChatMsg2LogMsg(const ChatMessageWrapper& chatMessage) {
			timestamp_ = convertUint32ToString(chatMessage.getTimestamp());
			content_ = chatMessage.getMessageText();
			usrIdentity_ = chatMessage.getUserName();
		}
		
		void setConnectionState(ConnectionState& state) {
			state_ = state;
		}
	
		void setContent(const std::string& content) {
			content_ = content;
		}
	
		void setTimestamp(const std::string& timestamp) {
			timestamp_ = timestamp;
		}
		
		void setUsrIdentity(const std::string& usrIdentity) {
			usrIdentity_ = usrIdentity;
		}
	
		const std::string& getContent() const { return content_; }
		ConnectionState getConnectionState() const { return state_; }
		std::string getTimestamp() const { return timestamp_; }

private:
		std::string content_;
		ConnectionState state_;
		std::string timestamp_;
		std::string usrIdentity_;
};


#endif /* LogMessage_hpp */
