cmake_minimum_required(VERSION 3.22)

add_library(mirror_dispatch_net net/DispatchSocket.cpp)


target_include_directories(mirror_dispatch_net PUBLIC 
        ${CMAKE_CURRENT_LIST_DIR}/net)

target_link_libraries(mirror_dispatch_net zmq)