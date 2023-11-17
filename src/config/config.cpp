#include <config/config.hpp>

namespace mirror {
    DispatchConfig* DispatchConfig::instance = nullptr;

    std::mutex DispatchConfig::access;

    DispatchConfig* DispatchConfig::getInstance() {
        std::lock_guard<std::mutex> guard(access);
        if(instance = nullptr) { instance = new DispatchConfig(); }
        return instance;
    }

    DispatchConfig::DispatchConfig() {
        this->logger_host = "localhost";
        this->logger_port = 4357;
    }
}