#pragma once

#include <string>
#include <mutex>

namespace mirror {
    class DispatchConfig {
    public:
        DispatchConfig(DispatchConfig &) = delete;
        DispatchConfig(DispatchConfig &&) = delete;
        DispatchConfig &operator=(const DispatchConfig &) = delete;
        DispatchConfig &operator=(const DispatchConfig &&) = delete;

        static DispatchConfig* getInstance();


        uint16_t getPublisherPort() { return publisher_port; }

        std::string& getLoggerHost() { return logger_host; }

        uint16_t getLoggerPort() { return logger_port; }
    
    protected:
        DispatchConfig();

    private:
        static DispatchConfig* instance;
        static std::mutex access;

        uint16_t publisher_port;
        std::string logger_host;
        uint16_t logger_port;
    };
}