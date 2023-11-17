#include <memory>
#include <mutex>
#include <queue>
#include <mirror/logger.h>
#include <io/docker.hpp>

#include <scheduler/job.hpp>
#include <memory>
#include <list>
#include <queue>
#include <iostream>

#include <scheduler/scheduler.hpp>

namespace mirror {
    DispatchScheduler::DispatchScheduler() {
        this->jobs = std::queue<DispatchJob>();
        this->logger = Logger::getInstance();
        this->docker = Docker::getInstance();
        logger->info("Scheduler configured.");
    }

    void DispatchScheduler::scheduleStart() {
        std::cout << "DispatchScheduler::scheduleStart()\n";
    }

    void DispatchScheduler::scheduleRestart() {
        std::cout << "DispatchScheduler::scheduleRestart()\n";
    }

    void DispatchScheduler::scheduleShutdown() {
        std::cout << "DispatchScheduler::scheduleShutdown()\n";
    }

    void DispatchScheduler::scheduleRefresh() {
        std::cout << "DispatchScheduler::scheduleRefresh()\n";
    }

    void DispatchScheduler::printModules() {
        std::cout << "DispatchScheduler::printModules()\n";
    }

    void DispatchScheduler::printJobs() {
        std::cout << "DispatchScheduler::printJobs()\n";
    }


}