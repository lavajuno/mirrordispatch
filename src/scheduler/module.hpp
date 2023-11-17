#pragma once

#include <string>
#include <scheduler/status.hpp>

namespace mirror {
    /**
     * DispatchModule represents a service that Dispatch controls. 
     */
    class DispatchModule {
    public:
        /**
         * Constructs a DispatchModule with a given name and IP address 
         */
        DispatchModule(std::string& name, std::string& address);

        /**
         * Constructs a DispatchModule
         */
        DispatchModule();

        /**
         * Gets this DispatchModule's name 
         */
        std::string getName() { return name; }

        /**
         * Gets this DispatchModule's IP address 
         */
        std::string getAddress() { return address; }

        /**
         * Gets this DispatchModule's status  
         */
        mirror::Status& getStatus() { return status; }

        /**
         * Sets this DispatchModule's status
         */
        void setStatus(mirror::Status status) { this->status = status; }
    
    private:
        std::string name;
        std::string address;
        mirror::Status status;
    };
}