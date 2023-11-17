#include <string>
#include <chrono>
#include <iostream>

#include <scheduler/status.hpp>

namespace mirror {

    /**
     * Public 
     */

    Status::Status(Status::States state) :
        state(state),
        creation(std::chrono::system_clock::now()),
        expiry(creation + std::chrono::minutes(1))
    {}

    Status::Status() : Status(States::UNKNOWN) {}

    bool Status::isExpired() {
        return std::chrono::system_clock::now() > expiry;
    }

    void Status::print() {
        std::cout << "Status:\n  Creation time: ";
        std::cout << std::chrono::system_clock::to_time_t(creation) << "\n";
        std::cout << "  Expiry time: ";
        std::cout << std::chrono::system_clock::to_time_t(expiry) << "\n";
        std::cout << "  State: ";
        switch(state) {
            case States::UP:
                std::cout << "UP";
            break;
            case States::WARN:
                std::cout << "WARN";
            break;
            case States::DOWN:
                std::cout << "DOWN";
            break;
            default:
                std::cout << "UNKNOWN";
            break;
        }
        std::cout << "\n";
    }

    /**
     * Private
     */
}