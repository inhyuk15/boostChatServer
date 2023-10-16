#include "Util.hpp"

uint64_t getCurTimestamp()
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

std::string convertUint64ToString(uint64_t timestamp)
{
    std::time_t seconds = static_cast<std::time_t>(timestamp / 1000);
    uint64_t millis = timestamp % 1000;

    std::time_t time = static_cast<std::time_t>(timestamp);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&seconds), "%Y-%m-%d;%H-%M-%S");
    ss << '.' << std::setw(3) << std::setfill('0') << millis;
    return ss.str();
}
