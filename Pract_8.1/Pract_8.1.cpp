#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Process {
	int id;
	int arrivalTime;
	int burstTime;
	int startTime;
	int endTime;
	int waitingTime;
};

void fcfs(vector<Process>& processes) {
	cout << "FCFS: " << endl;
	int n = processes.size();
	int currentTime = 0;
	float avgWaitingTime = 0.0;
	float avgTurnaroundTime = 0.0;

	for (int i = 0; i < n; i++) {
		Process& p = processes[i];
		if (p.arrivalTime > currentTime) {
			currentTime = p.arrivalTime;
		}
		p.startTime = currentTime;
		p.endTime = currentTime + p.burstTime;
		p.waitingTime = currentTime - p.arrivalTime;
		avgWaitingTime += p.waitingTime;
		avgTurnaroundTime += p.endTime - p.arrivalTime;
		currentTime = p.endTime;
	}

	cout << "ID\tArrival\tBurst\tStart\tEnd\tWaiting\n";
	for (int i = 0; i < n; i++) {
		Process& p = processes[i];
		cout << p.id << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t"
			<< p.startTime << "\t" << p.endTime << "\t" << p.waitingTime << "\n";
	}
	avgWaitingTime /= n;
	avgTurnaroundTime /= n;
	cout << "Average Waiting Time: " << avgWaitingTime << "\n";
	cout << "Average Turnaround Time: " << avgTurnaroundTime << "\n";
}

void rr(vector<Process>& processes, int timeQuantum) {
	cout << "RR:" << endl;
	int n = processes.size();
	queue<Process> readyQueue;
	int currentTime = 0;
	int totalBurstTime = 0;
	float avgWaitingTime = 0.0;
	float avgTurnaroundTime = 0.0;

	for (int i = 0; i < n; i++) {
		totalBurstTime += processes[i].burstTime;
		readyQueue.push(processes[i]);
	}

	while (!readyQueue.empty()) {
		Process p = readyQueue.front();
		readyQueue.pop();
		int remainingTime = p.burstTime;

		if (p.arrivalTime > currentTime) {
			readyQueue.push(p);
			currentTime++;
			continue;
		}

		if (remainingTime > timeQuantum) {
			p.burstTime -= timeQuantum;
			remainingTime -= timeQuantum;
			currentTime += timeQuantum;
			readyQueue.push(p);
		}
		else {
			p.startTime = currentTime;
			p.endTime = currentTime + remainingTime;
			p.waitingTime = currentTime - p.arrivalTime;
			avgWaitingTime += p.waitingTime;
			avgTurnaroundTime += p.endTime - p.arrivalTime;
			currentTime += remainingTime;
			cout << "Process " << p.id << " completed execution\n";
		}
	}

	cout << "ID\tArrival\tBurst\tStart\tEnd\tWaiting\n";
	for (int i = 0; i < n; i++) {
		Process& p = processes[i];
		cout << p.id << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t"
			<< p.startTime << "\t" << p.endTime << "\t" << p.waitingTime << "\n";
	}
	avgWaitingTime /= n;
	avgTurnaroundTime /= n;
	cout << "Average Waiting Time: " << avgWaitingTime << "\n";
	cout << "Average Turnaround Time: " << avgTurnaroundTime << "\n";
	cout << "Total time taken: " << currentTime << "\n";
	cout << "CPU utilization: " << (float)totalBurstTime / currentTime << "\n";
}

int main()
{
	vector<Process> processes = {
		{1, 0, 6},
		{2, 3, 2},
		{3, 10, 1},
		{4, 10, 3},
		{5, 12, 4}
	};

	fcfs(processes);

	cout << "\n";

	rr(processes, 5);
}
