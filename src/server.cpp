#include "server.hpp"
#include "fpng.h"
#include "npy.hpp"
#include <iostream>
#include <vector>


int main(int argc, char* argv[]) {
    fpng::fpng_init();
    Server a = Server();
    a.load_map(std::string("../map.npy"));
    return 0;
}

Server::Server() {
    // The standard tcp port
    m_addr = std::string("tcp://localhost:5555");

    std::vector<uint8_t> img;


    // ZMQ objects
    m_zmq_ctx = new zmq::context_t();
    m_socket = new zmq::socket_t(*m_zmq_ctx, ZMQ_REQ);

    std::cout << "Server running on tcp://localhost:5555" << std::endl;
    m_socket->bind(m_addr);
    m_socket->connect(m_addr);
}

Server::~Server() {
    if (m_socket != nullptr) {
        m_socket->unbind(m_addr);
        m_socket->disconnect(m_addr);
    }
    if (m_zmq_ctx != nullptr) {
        m_zmq_ctx->shutdown();
        m_zmq_ctx->close();
    }
}

void Server::start() {

}

void Server::load_map(const std::string map_path) {
    std::vector<unsigned long> shape {};
    bool fortran_order;

    npy::LoadArrayFromNumpy(map_path, shape, fortran_order, m_map);
}
