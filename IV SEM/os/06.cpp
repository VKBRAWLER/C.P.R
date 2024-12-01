// Implementation of FCFS
#include<iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cout << "Enter the number of process: ";
	cin >> n;
	cout << "	Enter the burst time of " << endl;
	vector<vector<int>> processes(n, {0, 0, 0, 0});
	int time = 0;
	for (int i = 0; i < n; i++) {
		processes[i][0] = i+1;
		cout << "P" << i+1 << " = ";
		cin >> processes[i][1];
		time +=processes[i][1];
		processes[i][2] = time;
		processes[i][3] = processes[i][2] - processes[i][1];
	}
	cout << "Pid\tBT\tTAT\tWT" << endl;
	for (int i = 0; i < n; i++) {
		cout << "P" << processes[i][0] << "\t" << processes[i][1] << "\t" << processes[i][2] << "\t" << processes[i][3] << endl;
	}
}