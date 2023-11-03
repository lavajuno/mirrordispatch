#pragma once

#include <string>

#include <scheduler/module.h>

namespace mirror {
    /**
     * DispatchJobs are scheduled by DispatchSchedule to take actions on modules. 
     */
    class DispatchJob {
    public:
        /**
         * The types of tasks that a DispatchJob can contain 
         */
        enum class Tasks {
            START,
            RESTART,
            CONFIGURE,
            STATUSCHECK,
            SHUTDOWN,
        };

        /**
         * Constructs a DispatchJob with a task and a target module 
         */
        DispatchJob(Tasks task, DispatchModule& target);

        /**
         * Gets this DispatchJob's task 
         */
        Tasks getTask() { return task; };

        /**
         * Gets this DispatchJob's target module 
         */
        DispatchModule& getTarget() { return target; }

    private:
        Tasks task;
        DispatchModule target;
    };
}