#ifndef ChatMessageWrapper_hpp
#define ChatMessageWrapper_hpp

#include "chat.pb.h"

class ChatMessageWrapper {
public:
	ChatMessageWrapper();
		ChatMessageWrapper(const std::string& userName, uint32_t timestamp, chat::DataType dataType);

		void setTextMessage(const std::string& messageText);
		void setImageMessage(const std::string& imageExtension, const std::vector<uint8_t>& imageData);
		void setDataType(chat::DataType dataType);
		void setSystemCode(chat::SystemCode systemCode);

		std::string encode() const;
		void decode(const std::string& input);

		std::string getUserName() const;
		uint32_t getTimestamp() const;
		chat::DataType getDataType() const;
		chat::SystemCode getSystemCode() const;

		std::string getMessageText() const;
		std::vector<uint8_t> getImageData() const;
		std::string getFileExtension() const;
	
		// For Debug
		std::string Base64Encode(const std::string &input);
		std::string Base64Decode(const std::string &input);
		// For Debug
private:
		chat::ChatMessage message_;
};

#endif /* ChatMessageWrapper_hpp */
