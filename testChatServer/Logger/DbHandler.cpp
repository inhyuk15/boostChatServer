#include "DbHandler.hpp"

DbHandler::DbHandler()
{
    context_ = redisConnect(hostname_, port_);
    if (context_ == NULL || context_->err)
    {
        if (context_)
        {
            std::cerr << "Error: " << context_->errstr << std::endl;
            redisFree(context_);
        }
        else
        {
            std::cerr << "Can't allocate redis context" << std::endl;
        }
        exit(1);
    }
    else
    {
        std::cout << "db connected" << std::endl;
    }
}

DbHandler::~DbHandler()
{
    redisFree(context_);
}

void DbHandler::storeLogMessage(const std::vector<LogMessage> &logMessages)
{
    for (const auto &logMessage : logMessages)
    {
        std::string key = "log:" + logMessage.getTimestamp();
        redisReply *reply;
        reply = (redisReply *)redisCommand(context_, "HSET %s timestamp %s", key.c_str(),
                                           logMessage.getTimestamp().c_str());
        freeReplyObject(reply);

        reply = (redisReply *)redisCommand(context_, "HSET %s usrIdentity %s", key.c_str(),
                                           logMessage.getUsrIdentity().c_str());
        freeReplyObject(reply);

        reply = (redisReply *)redisCommand(context_, "HSET %s state %d", key.c_str(),
                                           static_cast<int>(logMessage.getConnectionState()));
        freeReplyObject(reply);

        reply =
            (redisReply *)redisCommand(context_, "HSET %s content %s", key.c_str(), logMessage.getContent().c_str());
        freeReplyObject(reply);
    }
}
