#include "server.hpp"
// #include "fpng.h"
#include "npy.hpp"
#include <iostream>


int main(int argc, char* argv[]) {
    // fpng::fpng_init();
    Server a = Server();
    a.load_map();
    return 0;
}

Server::Server() {
    // ZMQ objects
    m_zmq_ctx = new zmq::context_t();
    m_socket = new zmq::socket_t(*m_zmq_ctx, ZMQ_REQ);

    std::cout << "Server running on tcp://localhost:5555" << std::endl;
    m_socket->connect("tcp://localhost:5555");
}

Server::~Server() {
    if (m_socket != nullptr) {
        m_socket->disconnect("tcp://localhost:5555");
    }
    if (m_zmq_ctx != nullptr) {
        m_zmq_ctx->shutdown();
        m_zmq_ctx->close();
    }
}

void Server::start() {

}

void Server::load_map() {
    std::vector<unsigned long> shape {};
    bool fortran_order;

    const std::string path{"../map.npy"};
    npy::LoadArrayFromNumpy(path, shape, fortran_order, m_map);
}
