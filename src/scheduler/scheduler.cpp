#include <scheduler/scheduler.h>

#include <memory>
#include <list>
#include <queue>
#include <iostream>

namespace mirror {
    DispatchScheduler::DispatchScheduler() {
        this->jobs = std::queue<DispatchJob>();
        this->logger = Logger::getInstance();
        this->publisher = DispatchPublisher::getInstance();
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