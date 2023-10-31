cmake_minimum_required(VERSION 3.22)
project(mirror_dispatch VERSION 0.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

add_subdirectory(lib/mirror_logging)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(dispatch_socket src/dispatchsocket.cpp)
target_link_libraries(dispatch_socket zmq)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(mirror_dispatch src/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
