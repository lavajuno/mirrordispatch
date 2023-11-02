#include <mirror/status.h>

#include <iostream>

namespace mirror {
    Status::Status() {
        state = States::UNKNOWN;
        creation = std::chrono::system_clock::now();
        expiry = creation + std::chrono::minutes(1);
    }

    void Status::print() {
        std::cout << "Status:\n  Creation time: ";
        std::cout << std::chrono::system_clock::to_time_t(creation) << std::endl;
        std::cout << "  Expiry time: ";
        std::cout << std::chrono::system_clock::to_time_t(expiry) << std::endl;
    }
}