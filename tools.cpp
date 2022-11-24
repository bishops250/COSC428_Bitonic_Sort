#include "constants.h"
#include <thread>

using namespace std;

unsigned int getThreads(void) noexcept{
    unsigned int thread_count = thread::hardware_concurrency();
    return thread_count;
}

bool isValidThreadCount(unsigned int thread_count) {
    unsigned int sys_threads = getThreads();
    return ( thread_count >= MIN_THREADS && thread_count <= sys_threads);
}

unsigned int setThreads(unsigned int thread_count) {
    unsigned int use_threads;
    if (thread_count == -1) {
        use_threads = getThreads();
    }
    else {
        use_threads = isValidThreadCount(thread_count) ? thread_count : MIN_THREADS;
    }
    return use_threads;
}

bool isValidDirection(unsigned int direction) {
    return
}
