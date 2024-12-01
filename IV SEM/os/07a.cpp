// Implimentation of SJF
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Process { int Pid; int BT; int AT; int CT; int TAT; int WT; };

bool complition_time (const Process &a, const Process &b) { return a.CT < b.CT; };

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

vector<Process> SJF(vector<Process> processes, int n) {
	int time = 0, completed = 0;
	while (completed < n) {
		int minBT = INT_MAX;
		Process *current = nullptr;
		for (Process &pr : processes) {
			if (pr.AT <= time && pr.CT == 0) {
				if (pr.BT < minBT) { current = &pr; minBT = pr.BT; }
			}
		}
		if (current) {
			time += current->BT;
			current->CT = time;
			current->TAT = current->CT - current->AT;
			current->WT = current->TAT - current->BT;
			current->CT = ++completed;
		} else { time++; }
	}
	return processes;
};

int main() {
	int n;
	vector<Process> processes;
  input_process_data(processes, n);
	processes = SJF(processes, n);
	output_process_data(processes, n);
}