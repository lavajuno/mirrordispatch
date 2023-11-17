#include <iostream>

#include <io/docker.hpp>
#include <scheduler/module.hpp>
#include <scheduler/status.hpp>
#include <scheduler/job.hpp>
#include <tests.hpp>
#include <cstring>

using namespace mirror;

int main(int argc, char* argv[]) {
    if(argc == 2 && strcmp(argv[1], "--test") == 0) { return Tests::run(); }
    std::cout << "MirrorDispatch" << std::endl;
}
