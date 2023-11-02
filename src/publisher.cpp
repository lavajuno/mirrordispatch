#include <mirror/publisher.h>
#include <mirror/module.h>
#include <mirror/job.h>

#include <exception>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include <iostream>

namespace mirror {
    std::mutex socketMutex;
    
    std::shared_ptr<DispatchPublisher> DispatchPublisher::getInstance() {
        static std::shared_ptr<DispatchPublisher> dispatchPublisher(
            new DispatchPublisher()
        );
        return dispatchPublisher;
    }

    void DispatchPublisher::configure(uint16_t port) {
        socket = zmq::socket_t(zmq_context, zmq::socket_type::pub);
        socket.bind("tcp://localhost:" + std::to_string(port));
        is_configured = true;
    }

    void DispatchPublisher::send() {
        std::cout << "TODO\n";
    }

    DispatchPublisher::DispatchPublisher() {
        is_configured = false;
    }
}