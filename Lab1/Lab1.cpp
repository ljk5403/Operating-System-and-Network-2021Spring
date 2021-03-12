#include "schedule.h"
#include <cstdlib>
#include <algorithm>

inline bool cmp(const PCB &x, const PCB &y) {
	return x.arrivalTime > y.arrivalTime;
}

vector<PCB> genProcess(int n) {
	vector<PCB> tmp;
	srand(47);
	cout << "Random create " << n << " processes" << endl;
	for (int i = 0; i < n; i++)
	{
		PCB x(
			rand() % 10,
			rand() % 10,
			rand() % 10 + 1
		);
		cout << x <<endl;
		tmp.push_back(x);
	}
	sort(tmp.begin(), tmp.end(), cmp);
	return tmp;
}

int main(int argc, char const *argv[])
{
	int numProcess = atoi(argv[1]);
	if(argc > 2 || !numProcess) {
		cout << "Invalid Argument Number";
		return 1;
	}
	vector<PCB> plist = genProcess(numProcess);
	Scheduler s;
	int time=0;
	while(!plist.empty() || !s.isVacant()) {
		cout << "==================" << endl
			 << "Time=" << time << endl
			 << "------------------Load arrival processed" << endl;
		while (plist.back().arrivalTime <= time && !plist.empty())
		{
			PCB latest = plist.back();
			cout << "Process " << latest.id << " arrived" << endl;
			s.arriveProcess(latest);
			plist.pop_back();
		}
		cout << "------------------Begin Scheduling" << endl;
		s.runSchedule(true);
		time++;
	}
	cout<<"All Process Finished";
	return 0;
}