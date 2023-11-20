#pragma once

#include <mutex>
#include <scheduler/module.hpp>

namespace mirror {
    class Docker {
    public:
        Docker(Docker &) = delete;
        Docker(Docker &&) = delete;
        Docker &operator=(const Docker &) = delete;
        Docker &operator=(const Docker &&) = delete;

        static Docker* getInstance();

        bool startModule(DispatchModule& module);

        bool stopModule(DispatchModule& module);

        bool restartModule(DispatchModule& module);

        bool refreshStatus();

        bool isUp(DispatchModule& module);
    protected:
        Docker();

        ~Docker();
    
    private:
        static Docker* instance;
        static std::mutex access;

        /**
         * Runs a command and returns its output.
         * If an error occurs, will return NULL. 
         */
        static std::string runCommand(std::string command);
    };
}