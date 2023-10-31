#include <mirror/dispatchsocket.h>

#include <exception>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>

namespace mirror {
    std::mutex socketMutex;
    
    std::shared_ptr<DispatchSocket> DispatchSocket::getInstance() {
        static std::shared_ptr<DispatchSocket> dispatchSocket(
            new DispatchSocket()
        );
        return dispatchSocket;
    }

    void DispatchSocket::configure(uint16_t port) {
        socket = zmq::socket_t(zmq_context, zmq::socket_type::router);
        socket.bind("inproc://localhost:" + std::to_string(port));
        is_configured = true;
    }

    DispatchSocket::DispatchSocket() {
        is_configured = false;
    }
}