#include <io/docker.hpp>
#include <scheduler/scheduler.hpp>
#include <scheduler/module.hpp>
#include <scheduler/status.hpp>
#include <scheduler/job.hpp>
#include <config/config.hpp>
#include <mirror/logger.h>
#include <tests.hpp>

#include <iostream>
#include <cstring>
#include <csignal>

using namespace mirror;

void terminate(int signal) {
    std::cout << "Terminated!";
    DispatchScheduler* scheduler = DispatchScheduler::getInstance();
    scheduler->interrupt();

}

int main(int argc, char* argv[]) {
    if(argc == 2 && strcmp(argv[1], "--test") == 0) { return Tests::run(); }
    std::cout << "MirrorDispatch" << std::endl;

    std::signal(SIGINT, terminate);

    Logger* logger = Logger::getInstance();
    logger->configure(4357, std::string("test"), std::string("localhost"));

    DispatchConfig* config = DispatchConfig::getInstance();
    DispatchScheduler* scheduler = DispatchScheduler::getInstance();
    std::cout << "Got instance\n";

}

