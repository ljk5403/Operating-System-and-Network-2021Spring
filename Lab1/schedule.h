#include <queue>
#include <vector>
#include "myprocess.h"
using namespace std;

class Scheduler
{
public:
    vector<PCB> finishedList;
    /**
     * Here I use to priority_queue to improve the time complexity.
     * But it is actually slower if we want to print all the process
     * at every second because priority_queue does not support iteration.
     */
    priority_queue<PCB> waitingQueue;

    void arriveProcess(PCB newProcess);

    void runSchedule(bool debug);

    void printStatus();

    bool isVacant();
};