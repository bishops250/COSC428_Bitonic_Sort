#include "constants.h"
#include "helper.h"
#include <thread>
#include <iostream>

unsigned int getThreads(void) noexcept
{
    unsigned int thread_count = std::thread::hardware_concurrency();
    if (thread_count == 0)
    {
        std::cout << "Unable to detect number of hardware threads." << std::endl;
        std::cout << "Setting threads =" << MIN_THREADS << std::endl;
        thread_count = MIN_THREADS;
    }
    return thread_count;
}

bool isValidThreadCount(int thread_count)
{
    int sys_threads = getThreads();
    return (thread_count >= MIN_THREADS && thread_count <= sys_threads);
}

unsigned int setThreads(int thread_count)
{
    unsigned int use_threads;
    if (thread_count == -1)
    {
        use_threads = getThreads();
    }
    else
    {
        use_threads = isValidThreadCount(thread_count) ? thread_count : MIN_THREADS;
    }
    return use_threads;
}

bool isValidDirection(int direction)
{
    return (direction == ASCENDING || direction == DESCENDING);
}

unsigned int setDirection(int direction)
{
    unsigned int dir;
    if (isValidDirection(direction))
    {
        dir = direction;
    }
    else
    {
        std::cout << "Invalid direction" << std::endl;
        std::cout << "Setting Direction: " << DESCENDING << std::endl;
        dir = DESCENDING;
    }
    return dir;
}

bool isValidSize(int size)
{
    return (size >= REQ_POW && size % REQ_POW == 0);
}
