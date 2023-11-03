#pragma once

#include <memory>
#include <mutex>
#include <queue>
#include <mirror/logger.h>
#include <net/publisher.h>

namespace mirror {
    /**
     * DispatchScheduler creates, queues, and publishes Jobs. 
     */
    class DispatchScheduler {
    public:
        DispatchScheduler(DispatchScheduler &&) = delete;
        DispatchScheduler(DispatchScheduler &) = delete;

        static std::shared_ptr<DispatchScheduler> getInstance();

        void scheduleStart();

        void scheduleRestart();

        void scheduleShutdown();

        void scheduleRefresh();

        void printModules();

        void printJobs();
        
    private:
        std::shared_ptr<DispatchPublisher> publisher;
        std::shared_ptr<Logger> logger;
        std::queue<DispatchJob> jobs;
        DispatchScheduler();
    };
}