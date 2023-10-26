#pragma once

#include <memory>
#include <zmq.hpp>

namespace mirror {
    class DispatchSocket {
    public:
        DispatchSocket(DispatchSocket &&) = delete;

        DispatchSocket(DispatchSocket &) = delete;

        static std::shared_ptr<DispatchSocket> getInstance();

    private:
        DispatchSocket();
    };
}