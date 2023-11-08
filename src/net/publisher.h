#pragma once

#include <memory>
#include <mutex>
#include <zmq.hpp>

#include <scheduler/job.h>
#include <config/config.h>
#include <mirror/logger.h>
#include <iostream>

namespace mirror {
    /**
     * DispatchPublisher is a singleton class that manages a publisher
     * socket that delivers jobs to the modules Dispatch controls.
     */
    class DispatchPublisher {
    public:
        DispatchPublisher(DispatchPublisher &) = delete;
        DispatchPublisher(DispatchPublisher &&) = delete;
        DispatchPublisher &operator=(const DispatchPublisher &) = delete;
        DispatchPublisher &operator=(const DispatchPublisher &&) = delete;

        static DispatchPublisher* getInstance();

        /**
         * Publishes a job
         */
        void publishJob(DispatchJob& job);

    protected:
        DispatchPublisher();

        ~DispatchPublisher() { socket.close(); }

    private:
        static DispatchPublisher* instance;

        static std::mutex access_mutex;

        static zmq::context_t publisher_context;

        Logger* logger;
        
        zmq::socket_t socket;

        std::string socket_addr;
    };
}