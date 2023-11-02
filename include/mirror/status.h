#pragma once

#include <string>
#include <chrono>

namespace mirror {
    /**
     * Status represents a limited-lifetime status of a single module.
     * Upon the expiration of a status, the scheduler will attempt to get a
     * new status.
     */
    class Status {
    public:
        Status();

        enum class States {
            UP,
            WARN,
            DOWN,
            UNKNOWN
        };
        
        States getState() { return state; };

        bool isExpired();

        void print();
    
    private:
        States state;
        std::chrono::system_clock::time_point creation;
        std::chrono::system_clock::time_point expiry;
    };
}