#pragma once

#include <string>
#include <mirror/status.h>

namespace mirror {
    class Module {
    public:
        Module(std::string& name, std::string& address);

        std::string getName() { return name; }

        std::string getAddress() { return address; }

        mirror::Status getStatus() { return status; }
    
    private:
        std::string name;
        std::string address;
        mirror::Status status;
    };
}