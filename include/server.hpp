#pragma once
#include <zmq.hpp>
#include <string>
#include <vector>


class Server {
    public:
        Server();
        ~Server();

        void load_map();

    private:
        void start();

        std::vector<int> m_map;

        zmq::context_t* m_zmq_ctx = nullptr;
        zmq::socket_t* m_socket = nullptr;
};
