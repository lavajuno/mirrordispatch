cmake_minimum_required(VERSION 3.22)
project(mirror_dispatch VERSION 0.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

# External libraries from source
add_subdirectory(lib/mirror-logging)

# Include header files
include_directories(${CMAKE_SOURCE_DIR}/src)

# Internal libraries from source
add_library(io
    src/io/docker.cpp
)

add_library(scheduler
    src/scheduler/job.cpp
    src/scheduler/module.cpp
    src/scheduler/scheduler.cpp
    src/scheduler/status.cpp
)

# Libraries to be linked internally
target_link_libraries(scheduler
    io
    mirror_logging
)

# Libraries to be linked to executable
link_libraries(
    mirror_logging
    io
    scheduler
)
add_executable(mirror_dispatch src/main.cpp src/tests.cpp)
