#include "Util.hpp"

uint32_t getCurTimestamp() {
    std::chrono::system_clock::time_point now =
        std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::seconds>(duration).count();
}

std::string convertUint32ToString(uint32_t timestamp) {
    std::time_t time = static_cast<std::time_t>(timestamp);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time), "%Y-%m-%d;%H-%M-%S");
    return ss.str();
}
