#include "myprocess.h"

PCB::PCB(int _priority, int _arrivalTime, int _estimatedRunTime)
{
	id = ++idAutoIncrement;
	alreadyUsedTime = 0;
	priority = _priority;
	arrivalTime = _arrivalTime;
	estimatedRunTime = _estimatedRunTime;
	status = Wait;
}

bool PCB::run()
{
	this->alreadyUsedTime += 1;
	if (this->alreadyUsedTime == this->estimatedRunTime)
	{
		this->status = Finish;
	}
	else
	{
		this->priority--;
	}
	return this->isFinished();
}

bool PCB::isFinished()
{
	return this->alreadyUsedTime == this->estimatedRunTime;
}

bool operator<(const PCB &x, const PCB &y)
{
	return x.priority < y.priority;
}

int PCB::idAutoIncrement = 0;

ostream &operator<<(ostream &out, const PCB &pcb)
{
	out << "Process ID:" << pcb.id << "\t"
		<< "Arrival Time:" << pcb.arrivalTime << "\t"
		<< "Used Time/Estimated RunTime:" << pcb.alreadyUsedTime << "/" << pcb.estimatedRunTime << "\t"
		<< "Priority:" << pcb.priority << "\t"
		<< "Status:" << pcb.status;
	return out;
}