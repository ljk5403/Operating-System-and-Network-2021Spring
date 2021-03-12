#include <iostream>
using namespace std;

enum ProcessStatus
{
    Wait,
    Run,
    Finish
};
class PCB
{
public:
    static int idAutoIncrement;
    int id, priority;
    int arrivalTime, estimatedRunTime, alreadyUsedTime;
    ProcessStatus status;
    PCB(int _priority, int _arrivalTime, int _estimatedRunTime);
    bool run();
    bool isFinished();
    friend bool operator<(const PCB &x, const PCB &y);
    friend ostream &operator<<(ostream &out, const PCB &pcb);
};
bool operator<(const PCB &x, const PCB &y);
ostream &operator<<(ostream &out, const PCB &pcb);
