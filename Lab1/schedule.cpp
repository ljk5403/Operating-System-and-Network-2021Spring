#include "schedule.h"

void Scheduler::arriveProcess(PCB newProcess)
{
    this->waitingQueue.push(newProcess);
}

void Scheduler::runSchedule(bool debug)
{
    if (this->isVacant())
        return;
    PCB processToRun = this->waitingQueue.top();
    this->waitingQueue.pop();
    if (debug)
        cout << "Current running proces: " << endl
             << processToRun << endl;
    if (processToRun.run())
        this->finishedList.push_back(processToRun);
    else
        this->waitingQueue.push(processToRun);
    if (debug)
        this->printStatus();
}

void Scheduler::printStatus()
{
    cout << "Finished Processes:" << endl;
    for (int i = 0; i < this->finishedList.size(); i++)
        cout << finishedList[i] << endl;
    // very inefficient iteration
    cout << "Waiting Queue:" << endl;
    vector<PCB> tmp;
    while (!this->waitingQueue.empty())
    {
        PCB top = this->waitingQueue.top();
        this->waitingQueue.pop();
        cout << top << endl;
        tmp.push_back(top);
    }
    for (int i = 0; i < tmp.size(); i++)
        this->waitingQueue.push(tmp[i]);
}

bool Scheduler::isVacant()
{
    return this->waitingQueue.empty();
}
