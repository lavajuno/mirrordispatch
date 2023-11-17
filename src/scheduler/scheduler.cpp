#include <mirror/logger.h>
#include <io/docker.hpp>
#include <scheduler/job.hpp>

#include <mutex>
#include <memory>
#include <list>
#include <queue>
#include <iostream>
#include <thread>

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
        flag_interrupt = false;
        std::thread schedulerThread(runScheduler);
        schedulerThread.detach();
        std::cout << "Scheduler configured.\n";
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

    void DispatchScheduler::pushJob(DispatchJob& job) {
        std::lock_guard<std::mutex> guard(access);
        jobs.push(job);
    }

    DispatchJob DispatchScheduler::nextJob() {
        std::lock_guard<std::mutex> guard(access);
        return jobs.front();
    }

    void DispatchScheduler::popJob() {
        std::lock_guard<std::mutex> guard(access);
        jobs.pop();
    }

    void DispatchScheduler::runScheduler() {
        std::cout << "Scheduler thread started.\n";
        DispatchScheduler* scheduler = DispatchScheduler::getInstance();
        std::cout << "Got instance.\n";
    }

}