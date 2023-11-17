
#include <io/docker.hpp>
#include <mutex>

namespace mirror {

    Docker* Docker::instance = nullptr;
    std::mutex Docker::access;

    Docker* Docker::getInstance() {
        std::lock_guard<std::mutex> lock(access);
        if(instance == nullptr) { instance = new Docker(); }
        return instance;
    }

    Docker::Docker() {}
    Docker::~Docker() { delete instance; }


    std::string Docker::runCommand(std::string command) {
        std::string output = "";
        FILE* pipe = popen(command.c_str(), "r");
        if(!pipe) { return nullptr; }
        try {
            char buffer[1024];
            while(fgets(buffer, 1024, pipe) != NULL) {
                output += buffer;
            }
        } catch(...) { output = nullptr; }
        pclose(pipe);
        return nullptr;
    }


}