#ifndef helper_H
#define helper_H

unsigned int getThreads(void) noexcept;

bool isValidThreadCount(int thread_count);

unsigned int setThreads(int thread_count);
bool isValidDirection(int direction);

unsigned int setDirection(int direction);

bool isValidSize(int size);

#endif
