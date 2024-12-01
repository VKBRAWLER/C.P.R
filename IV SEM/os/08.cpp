// Implimentation of Priority Scheduling
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Process { int Pid; int BT; int AT; int CT; int TAT; int WT; int PR; };

bool complition_time (const Process &a, const Process &b) { return a.CT < b.CT; }
bool arrival_time (const Process &a, const Process &b) { return a.AT < b.AT; }
bool burst_time (const Process &a, const Process &b) { return a.BT < b.BT; }
bool priority (const Process &a, const Process &b) { return a.PR > b.PR; }

void input_process_data(vector<Process> &processes, int &n) {
	cout << "Enter the number of process: "; cin >> n;
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
	cout << "Enter the priority of " << endl;
	for (int i = 0; i < n; i++) {
	  cout << "P" << i + 1 << " = "; cin >> processes[i].PR;
	}
};

void output_process_data(vector<Process> processes, int n) {
	sort(processes.begin(), processes.end(), complition_time);
	cout << "Pid\tBT\tAT\tCT\tTAT\tWT\tPR" << endl;
	for (int i = 0; i < n; i++) {
		cout << "P" << processes[i].Pid << "\t" << processes[i].BT << "\t" << processes[i].AT << "\t" << processes[i].CT << "\t" << processes[i].TAT << "\t" << processes[i].WT << "\t" << processes[i].PR << endl;
	}
	double totalWT = 0, totalTAT = 0;
	for (const Process &pr : processes) { totalWT += pr.WT; totalTAT += pr.TAT; }
	cout << "Average Waiting Time: " << totalWT / n << endl;
	cout << "Average Turn Around Time: " << totalTAT / n << endl;
};

vector<Process> PS(vector<Process> processes, int n) {
  vector<Process> running;
  int time = 0, completed = 0; 
	while (completed < n) {
    for (Process &pr: processes) { if (pr.AT <= time && pr.CT == 0) { running.push_back(pr); pr.CT = -1; } }
    Process *current = nullptr;
    sort(running.begin(), running.end(), priority);
    for (Process &p: running) {
      if (!p.TAT) { current = &p; break; }
    }
    if (current) {
      time += current->BT;
      current->CT = time;
      current->TAT = current->CT - current->AT;
      current->WT = current->TAT - current->BT;
      completed++;
    } else { time++; }
  }
	return running;
} 

int main() {
	int n;
	vector<Process> processes;
  input_process_data(processes, n);
	processes = PS(processes, n);
	output_process_data(processes, n);
}