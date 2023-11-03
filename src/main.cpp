#include <iostream>

#include <net/publisher.h>
#include <scheduler/module.h>
#include <scheduler/status.h>
#include <scheduler/job.h>
#include <tests.h>

using namespace mirror;

int main(int argc, char* argv[]) {
    if(argc == 2 && strcmp(argv[1], "--test") == 0) { return Tests::run(); }
    std::cout << "MirrorDispatch" << std::endl;
}
