cmake_minimum_required(VERSION 3.15)
project(path_calc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# load in pkg-config support
find_package(PkgConfig)
# use pkg-config to get hints for 0mq locations
pkg_check_modules(PC_ZeroMQ QUIET zmq)

# use the hint from above to find where 'zmq.hpp' is located
find_path(ZeroMQ_INCLUDE_DIR
        NAMES zmq.hpp
        PATHS ${PC_ZeroMQ_INCLUDE_DIRS}
        )

# use the hint from above to find the location of libzmq
find_library(ZeroMQ_LIBRARY
        NAMES zmq
        PATHS ${PC_ZeroMQ_LIBRARY_DIRS}
        )

set(SRC
    src/server.cpp
    # src/fpng.cpp
    )

set(HDR
    include/server.hpp
    # include/fpng.h
    include/npy.hpp
    )

# The server exec
add_executable(server ${SRC})
target_include_directories(server PUBLIC ${ZeroMQ_INCLUDE_DIR} include)
target_link_libraries(server PUBLIC ${ZeroMQ_LIBRARY})