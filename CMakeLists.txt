cmake_minimum_required(VERSION 3.15)
project(path_calc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message("${CMAKE_MODULE_PATH}")
find_package(zmq REQUIRED)

set(SRC
    src/server.cpp
    )

set(HDR
    include/server.hpp
    )

# The server exec
add_executable(server ${SRC})
target_include_directories(server PRIVATE ${HDR} ${zmq})
target_link_libraries(server ${zmq_LIBS})