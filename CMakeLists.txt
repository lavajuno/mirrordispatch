cmake_minimum_required(VERSION 3.22)
project(mirror_dispatch VERSION 0.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

add_executable(mirror_dispatch src/main.cpp)

add_subdirectory(lib/mirror_logging)
add_subdirectory(src)

target_link_libraries(mirror_dispatch mirror_logging)
target_link_libraries(mirror_dispatch mirror_dispatch_net)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
