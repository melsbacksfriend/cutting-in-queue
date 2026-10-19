#include "jobqueue.h"

int main()
{
    JobQueue jq;
    jq.insert(Job("This JoJ comes first", 5));
    jq.insert(Job("This JoJ comes third", 3));
    jq.insert(Job("This JoJ comes fifth", 1));
    jq.insert(Job("This JoJ comes fourth", 2));
    jq.insert(Job("This JoJ comes second", 4));

    while(!jq.empty())
    {
        jq.runHighestPriority();
        std::cout << "\n";
    }
}
