#ifndef JOBQUEUE_H
#define JOBQUEUE_H

#include "priorityqueue.h"
#include "src/job.hpp"

class JobQueue {
public:
    JobQueue();
    void insert(const Job& j);
    void runHighestPriority();
    bool empty();

private:
    PriorityQueue<Job> pq;
};

#endif // JOBQUEUE_H
