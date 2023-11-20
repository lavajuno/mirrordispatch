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

        void pushJob(DispatchJob& job);

        DispatchJob nextJob();

        void popJob();
        
        void interrupt();

    protected:
        DispatchScheduler();

        ~DispatchScheduler();

        static void runScheduler();

        bool isInterrupted() { return flag_interrupt; }

    private:
        static DispatchScheduler* instance;
        static std::mutex access;
        
        Docker* docker;
        Logger* logger;
        std::queue<DispatchJob> jobs;

        std::thread scheduler_thread;

        bool flag_interrupt;        
    };
}