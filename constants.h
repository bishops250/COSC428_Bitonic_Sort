#ifndef constants_H
#define constants_H

#define MIN_THREADS 1
// min required threads to execute program.
// serial execution

#define MIN_INPUT_THREADS -1
// executes bitonic sort with all applicable hardware threads

#define DEFAULT_DIR 1
// default bitonic sort direction is 1 for Descending

#define REQ_POW 2
// size of input must be a power of 2.

typedef enum
{
    ASCENDING = 0,
    DESCENDING = 1
} DIRECTION_et;

#endif