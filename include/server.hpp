#pragma once
#include <zmq.hpp>
#include <string>
#include <vector>


class Server {
    public:
        Server();
        ~Server();

        void load_map(const std::string map_path);

    private:
        void start();

        std::string m_addr;
        std::vector<double> m_map;

        zmq::context_t* m_zmq_ctx = nullptr;
        zmq::socket_t* m_socket = nullptr;
};
