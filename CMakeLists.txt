cmake_minimum_required(VERSION 3.22)
project(mirror_dispatch VERSION 0.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/mirror_logging)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
add_library(MirrorDispatch ${SOURCES})

target_link_libraries(MirrorDispatch zmq)

link_libraries(MirrorDispatch)
add_executable(mirror_dispatch src/main.cpp)
