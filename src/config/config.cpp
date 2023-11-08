#include <config/config.h>

namespace mirror {
    DispatchConfig* DispatchConfig::instance = nullptr;

    std::mutex DispatchConfig::access_mutex;

    DispatchConfig* DispatchConfig::getInstance() {
        std::lock_guard<std::mutex> guard(access_mutex);
        if(instance = nullptr) { instance = new DispatchConfig(); }
        return instance;
    }

    DispatchConfig::DispatchConfig() {
        this->publisher_port = 4358;
        this->logger_host = "localhost";
        this->logger_port = 4357;
    }
}