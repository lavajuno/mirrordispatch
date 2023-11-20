
#include <io/docker.hpp>
#include <mutex>
#include <sstream>
#include <iostream>

namespace mirror {

    Docker* Docker::instance = nullptr;
    std::mutex Docker::access;

    Docker* Docker::getInstance() {
        std::lock_guard<std::mutex> lock(access);
        if(instance == nullptr) { instance = new Docker(); }
        return instance;
    }

    Docker::Docker() {}
    Docker::~Docker() {}

    bool Docker::startModule(DispatchModule& module) {
        std::cout << "Starting module " << module.getName() << "\n";
        std::lock_guard<std::mutex> lock(access);
        std::stringstream command;
        command << "docker start " << module.getName();
        std::cout << "Running the command \"" << command.str() << "\"...\n";
        std::string result = runCommand(command.str());
        std::cout << "Result: \"" << result << "\"\n";
        return false;
    }


    std::string Docker::runCommand(std::string command) {
        std::string output = "";
        FILE* pipe = popen(command.c_str(), "r");
        if(!pipe) {
            std::cout << "Couldn't open pipe!\n";
            return nullptr;
        }
        try {
            char buffer[512];
            while(fgets(buffer, 512, pipe) != NULL) {
                output += buffer;
            }
        } catch(...) { 
            std::cout << "Error reading from stream!\n";
            output = nullptr;
        }
        pclose(pipe);
        return output;
    }


}