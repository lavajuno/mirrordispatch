#include <mirror/logger.h>
#include <io/docker.hpp>
#include <scheduler/job.hpp>

#include <mutex>
#include <memory>
#include <list>
#include <queue>
#include <iostream>

#include <scheduler/scheduler.hpp>

namespace mirror {

    DispatchScheduler* DispatchScheduler::instance = nullptr;

    std::mutex DispatchScheduler::access;

    DispatchScheduler* DispatchScheduler::getInstance() {
        std::lock_guard<std::mutex> guard(access);
        if(instance == nullptr) { instance = new DispatchScheduler(); }
        return instance;
    }

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