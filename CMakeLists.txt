cmake_minimum_required(VERSION 3.22)
project(mirror_dispatch VERSION 0.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

# External libraries from source
add_subdirectory(lib/mirror_logging)

# Include header files
include_directories(${CMAKE_SOURCE_DIR}/src)

# Internal libraries from source
add_library(DispatchNet
    src/net/publisher.cpp
)
add_library(DispatchScheduler
    src/scheduler/job.cpp
    src/scheduler/module.cpp
    src/scheduler/scheduler.cpp
    src/scheduler/status.cpp
)

# Libraries to be linked internally
target_link_libraries(DispatchNet
    DispatchScheduler
    mirror_logging
    zmq
)
target_link_libraries(DispatchScheduler
    DispatchNet
    mirror_logging
    zmq
)

# Libraries to be linked to executable
link_libraries(
    DispatchNet
    DispatchScheduler
    mirror_logging
)
add_executable(mirror_dispatch src/main.cpp src/tests.cpp)
