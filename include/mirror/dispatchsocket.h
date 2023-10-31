#pragma once

#include <memory>
#include <zmq.hpp>
#include <mutex>

namespace mirror {
    class DispatchSocket {
    public:
        DispatchSocket(DispatchSocket &&) = delete;

        DispatchSocket(DispatchSocket &) = delete;

        static std::shared_ptr<DispatchSocket> getInstance();

        void configure(uint16_t port);

        void send();

    private:
        std::mutex socket_mutex;

        bool is_configured;

        zmq::socket_t socket;
        
        zmq::context_t zmq_context{1, 1};

        DispatchSocket();
    };
}