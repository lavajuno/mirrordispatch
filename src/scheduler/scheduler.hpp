#pragma once

#include <io/docker.hpp>
#include <scheduler/job.hpp>
#include <mirror/logger.h>
#include <queue>

namespace mirror {
    /**
     * DispatchScheduler creates, queues, and publishes Jobs. 
     */
    class DispatchScheduler {
    public:
        DispatchScheduler(DispatchScheduler &) = delete;
        DispatchScheduler(DispatchScheduler &&) = delete;
        DispatchScheduler &operator=(const DispatchScheduler &) = delete;
        DispatchScheduler &operator=(const DispatchScheduler &&) = delete;

        static DispatchScheduler* getInstance();

        void scheduleStart();

        void scheduleRestart();

        void scheduleShutdown();

        void scheduleRefresh();

        void printModules();

        void printJobs();
        
    protected:
        DispatchScheduler();

        ~DispatchScheduler();
    private:
        Docker* docker;
        Logger* logger;
        std::queue<DispatchJob> jobs;
    };
}