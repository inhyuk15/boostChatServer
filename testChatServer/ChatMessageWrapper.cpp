#include "ChatMessageWrapper.hpp"

#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>

ChatMessageWrapper::ChatMessageWrapper()
{
}

ChatMessageWrapper::ChatMessageWrapper(const std::string &userName, uint64_t timestamp, chat::DataType dataType)
{
    message_.set_user_name(userName);
    message_.set_timestamp(timestamp);
    message_.set_data_type(dataType);
}

void ChatMessageWrapper::setTextMessage(const std::string &messageText)
{
    message_.set_message_text(messageText);
}

void ChatMessageWrapper::setImageMessage(const std::string &imageExtension, const std::vector<uint8_t> &imageData)
{
    message_.set_file_extension(imageExtension);
    message_.set_image_data(imageData.data(), imageData.size());
}

void ChatMessageWrapper::setDataType(chat::DataType dataType)
{
    message_.set_data_type(dataType);
}

void ChatMessageWrapper::setSystemCode(chat::SystemCode systemCode)
{
    message_.set_system_code(systemCode);
}

std::string ChatMessageWrapper::encode() const
{
    std::string output;
    message_.SerializeToString(&output);
    return output;
}

void ChatMessageWrapper::decode(const std::string &input)
{
    message_.ParseFromString(input);
}

std::string ChatMessageWrapper::getUserName() const
{
    return message_.user_name();
}

uint64_t ChatMessageWrapper::getTimestamp() const
{
    return message_.timestamp();
}

chat::DataType ChatMessageWrapper::getDataType() const
{
    return message_.data_type();
}

chat::SystemCode ChatMessageWrapper::getSystemCode() const
{
    return message_.system_code();
}

std::string ChatMessageWrapper::getMessageText() const
{
    return message_.message_text();
}

std::vector<uint8_t> ChatMessageWrapper::getImageData() const
{
    return std::vector<uint8_t>(message_.image_data().begin(), message_.image_data().end());
}

std::string ChatMessageWrapper::getFileExtension() const
{
    return message_.file_extension();
}

// For Debug
std::string ChatMessageWrapper::Base64Encode(const std::string &input)
{
    using namespace boost::archive::iterators;

    typedef base64_from_binary<transform_width<std::string::const_iterator, 6, 8>> Base64EncodeIterator;

    std::string encodedString(Base64EncodeIterator(input.begin()), Base64EncodeIterator(input.end()));

    size_t num = (3 - input.length() % 3) % 3;
    for (size_t i = 0; i < num; i++)
    {
        encodedString.push_back('=');
    }
    return encodedString;
}

std::string ChatMessageWrapper::Base64Decode(const std::string &input)
{
    using namespace boost::archive::iterators;

    typedef transform_width<binary_from_base64<std::string::const_iterator>, 8, 6> Base64DecodeIterator;

    return std::string(Base64DecodeIterator(input.begin()), Base64DecodeIterator(input.end()));
}
// For Debug
