#include <scheduler/job.h>
#include <scheduler/module.h>

namespace mirror {
    DispatchJob::DispatchJob(DispatchJob::Tasks task, DispatchModule& target) {
        this->task = task;
        this->target = target;
    }
}