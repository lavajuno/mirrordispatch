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
        DispatchScheduler();

        ~DispatchScheduler();

        void scheduleStart();

        void scheduleRestart();

        void scheduleShutdown();

        void scheduleRefresh();

        void printModules();

        void printJobs();
        
    private:
        DispatchPublisher* publisher;
        Logger* logger;
        std::queue<DispatchJob> jobs;
        
    };
}