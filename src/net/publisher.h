#pragma once

#include <memory>
#include <mutex>
#include <zmq.hpp>

#include <scheduler/job.h>

namespace mirror {
    /**
     * DispatchPublisher is a singleton class that manages a publisher
     * socket that delivers jobs to the modules Dispatch controls.
     */
    class DispatchPublisher {
    public:
        DispatchPublisher(DispatchPublisher &&) = delete;

        DispatchPublisher(DispatchPublisher &) = delete;

        /**
         * Returns a shared pointer to this DispatchPublisher 
         */
        static std::shared_ptr<DispatchPublisher> getInstance();

        /**
         * Sets up this DispatchPublisher with a given port number 
         */
        void configure(uint16_t port);

        /**
         * Publishes a job
         */
        void publishJob(DispatchJob& job);

    private:
        std::mutex socket_mutex;

        bool is_configured;

        zmq::socket_t socket;
        
        zmq::context_t zmq_context{1, 1};

        DispatchPublisher();
    };
}