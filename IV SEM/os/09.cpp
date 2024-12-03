// Implimentation of Round Robin
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Process { int Pid; int BT; int AT; int CT; int TAT; int WT; };

bool complition_time (const Process &a, const Process &b) { return a.CT < b.CT; }
bool arrival_time (const Process &a, const Process &b) { return a.AT < b.AT; }
bool burst_time (const Process &a, const Process &b) { return a.BT < b.BT; }

void input_process_data(vector<Process> &processes, int &n, int &t) {
	cout << "Enter the number of process: "; cin >> n;
	cout << "Enter the time instance: "; cin >> t;
	processes.resize(n);
	cout << "Enter the burst time of " << endl;
	for (int i = 0; i < n; i++) {
	  processes[i].Pid = i + 1;
	  cout << "P" << i + 1 << " = "; cin >> processes[i].BT;
	}
	cout << "Enter the arrival time of " << endl;
	for (int i = 0; i < n; i++) {
	  cout << "P" << i + 1 << " = "; cin >> processes[i].AT;
	}
};

void output_process_data(vector<Process> processes, int n) {
	sort(processes.begin(), processes.end(), complition_time);
	cout << "Pid\tBT\tAT\tCT\tTAT\tWT" << endl;
	for (int i = 0; i < n; i++) {
		cout << "P" << processes[i].Pid << "\t" << processes[i].BT << "\t" << processes[i].AT << "\t" << processes[i].CT << "\t" << processes[i].TAT << "\t" << processes[i].WT << endl;
	}
	double totalWT = 0, totalTAT = 0;
	for (const Process &pr : processes) { totalWT += pr.WT; totalTAT += pr.TAT; }
	cout << "Average Waiting Time: " << totalWT / n << endl;
	cout << "Average Turn Around Time: " << totalTAT / n << endl;
};

vector<Process> RR(vector<Process> processes, int n, int t) {
  vector<Process> copy = processes;
	sort(processes.begin(), processes.end(), arrival_time);
	queue<int> running;
  int time = 0, completed = 0;
	while (completed < n) {
    for (Process &pr: processes) { if (pr.AT <= time && pr.CT == 0) { running.push(pr.Pid); pr.CT = -1; } }
    if (!running.empty()) {
      if (processes[running.front() - 1].BT <= t) {
        time += processes[running.front() - 1].BT;
        processes[running.front() - 1].CT = time;
        completed++;
      }
      else {
        time += t;
        processes[running.front() - 1].BT -= t;
        for (Process &pr: processes) { if (pr.AT <= time && pr.CT == 0) { running.push(pr.Pid); pr.CT = -1; } }
        running.push(running.front());
      }
      running.pop();
    }
    else { time++; }
	}

  for (int i = 0; i < n; i++) {
    processes[i].BT = copy[i].BT;
    processes[i].TAT = processes[i].CT - processes[i].AT;
    processes[i].WT = processes[i].TAT - processes[i].BT;
  }
    	
	return processes;
}

int main() {
	int n, t;
	vector<Process> processes;
  input_process_data(processes, n, t);
	processes = RR(processes, n, t);
	output_process_data(processes, n);
}