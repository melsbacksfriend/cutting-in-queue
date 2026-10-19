#include "jobqueue.h"

JobQueue::JobQueue()
{
    pq = PriorityQueue<Job>();
}

void JobQueue::insert(const Job& j)
{
    pq.push(j);
}

void JobQueue::runHighestPriority()
{
    Job j = pq.pop();
    j.execute();
}

bool JobQueue::empty()
{
    return pq.empty();
}