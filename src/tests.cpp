#include <iostream>

#include <scheduler/job.h>
#include <scheduler/module.h>
#include <net/publisher.h>
#include <scheduler/scheduler.h>
#include <scheduler/status.h>
#include <tests.h>

namespace mirror {
    int Tests::run() {
        int test_fails = 0;
        std::cout << "=== MirrorDispatch: Running tests. ===" << std::endl;

        test_fails += Tests::testStatus() ? 0 : 1;

        if(test_fails > 0) {
            std::cout << "=== MirrorDispatch: " << test_fails;
            std::cout << " tests failed. ===" << std::endl;
        }
        return 0;
    };

    bool Tests::testStatus() {
        Status status = Status();
        status.print();
        return true;
    }
}
