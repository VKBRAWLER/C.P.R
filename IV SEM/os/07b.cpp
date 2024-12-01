// Implimentation of SRTF
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Process { int Pid; int BT; int AT; int CT; int TAT; int WT; };

bool complition_time (const Process &a, const Process &b) { return a.CT < b.CT; }
bool arrival_time (const Process &a, const Process &b) { return a.AT < b.AT; }
bool burst_time (const Process &a, const Process &b) { return a.BT < b.BT; }

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

vector<Process> SRTF(vector<Process> processes, int n) {
	sort(processes.begin(), processes.end(), arrival_time);
	vector<Process> running;
	for (int time = 0, completed = 0;completed < n; time++) {
		for (int i = 0; i < n; i++) {
			if (processes[i].AT <= time && processes[i].CT == 0) {
				running.push_back(processes[i]);
				processes[i].CT = 1;
			}
		}
		sort(running.begin(), running.end(), burst_time);
		for (Process &pr : running) { 
				if (pr.BT) { 
					pr.BT--;
				  if (pr.BT == 0) { pr.CT = time+1; completed++; }
				break;
			}
		}
	}
	for (Process &run : running) {
		for (Process &pr : processes) { if (pr.Pid == run.Pid) { run.BT = pr.BT; break; } }
		run.TAT = run.CT - run.AT;
		run.WT = run.TAT - run.BT;
	}
	return running;
}

int main() {
	int n;
	vector<Process> processes;
  input_process_data(processes, n);
	processes = SRTF(processes, n);
	output_process_data(processes, n);
}