#include <iostream>

#include <mirror/publisher.h>
#include <mirror/module.h>
#include <mirror/status.h>
#include <mirror/job.h>
#include <mirror/tests.h>

using namespace mirror;

int main(int argc, char* argv[]) {
    if(argc == 2 && strcmp(argv[1], "--test") == 0) { return Tests::run(); }
    std::cout << "MirrorDispatch" << std::endl;
}
