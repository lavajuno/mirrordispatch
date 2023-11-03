#include <scheduler/scheduler.h>

#include <memory>
#include <list>
#include <queue>
#include <iostream>

namespace mirror {
    std::shared_ptr<DispatchScheduler> DispatchScheduler::getInstance() {
        static std::shared_ptr<DispatchScheduler> scheduler(new DispatchScheduler());
        return scheduler;
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

    DispatchScheduler::DispatchScheduler() {
        this->jobs = std::queue<DispatchJob>();
        this->logger = Logger::getInstance();
        this->publisher = DispatchPublisher::getInstance();
        logger->configure(4357, "Dispatch");
        publisher->configure(4358);
        logger->info("Scheduler configured.");
    }
}