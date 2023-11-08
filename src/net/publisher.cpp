#include <net/publisher.h>
#include <scheduler/module.h>
#include <scheduler/job.h>

#include <exception>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>

namespace mirror {

    zmq::context_t DispatchPublisher::publisher_context(1, 1);

    DispatchPublisher* DispatchPublisher::instance = nullptr;

    std::mutex DispatchPublisher::access_mutex;

    DispatchPublisher* DispatchPublisher::getInstance() {
        std::lock_guard<std::mutex> guard(access_mutex);
        if(instance == nullptr) { instance = new DispatchPublisher(); }
        return instance;
    }
    
    DispatchPublisher::DispatchPublisher() {
        this->logger = Logger::getInstance();
        DispatchConfig* config = DispatchConfig::getInstance();
        this->socket_addr = "tcp://localhost:" + config->getPublisherPort();
        socket.bind(socket_addr);
    }

    void DispatchPublisher::publishJob(DispatchJob& job) {
        std::cout << "TODO\n";
    }
}