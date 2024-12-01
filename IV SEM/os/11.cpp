// WAP for Deadlock Avoidance
#include<iostream>
#include<vector>
using namespace std;

struct Process { vector<int> allocated; vector<int> needed; };

bool checkAvailability (vector<int> req,vector<int> alo, vector<int> avi, int r_size) {
  for (int i = 0; i < r_size; i++) { if (req[i] > avi[i] + alo[i]) return false; }
  return true;
}

vector<int> BA(vector<Process> processes, vector<int> available, int p_size, int r_size) {
  vector<int> completed;
  vector<bool> visited(p_size, false);
  while (completed.size() < p_size) {
    bool change = false;
    for (int i = 0; i < p_size; i++) {
      if (!visited[i] && checkAvailability(processes[i].needed, processes[i].allocated, available, r_size)) {
        for (int j = 0; j < r_size; j++) { available[j] += processes[i].allocated[j]; }
        completed.push_back(i); visited[i] = true; change = true;
      }
    }
    if (!change) return vector<int>{-1};
  }
  return completed;
}

int main() {
  int p_size, r_size;
  cout << "Enter the number of processes: "; cin >> p_size;
  cout << "Enter the number of resources: "; cin >> r_size;

  vector<Process> processes(p_size, Process{vector<int>(r_size), vector<int>(r_size)});
  for (int i = 0; i < p_size; i++) {
    cout << "Enter the resources allocated by process P" << i << ": ";
    for (int j = 0; j < r_size; j++) { cin >> processes[i].allocated[j]; }
  }
  for (int i = 0; i < p_size; i++) {
    cout << "Enter the resources needed by process P" << i << ": ";
    for (int j = 0; j < r_size; j++) { cin >> processes[i].needed[j]; }
  }

  vector<int> available(r_size);
  cout << "Enter the available resources here: ";
  for (int i = 0; i < r_size; i++) { cin >> available[i]; }

  vector<int> result = BA(processes, available, p_size, r_size);
  if (result[0] == -1) cout << "Unsafe System";
  else {
    for (int i = 0; i < p_size; i++) {
      cout << "P" << result[i] << " -> ";
    }
    cout << "end";
  }
}