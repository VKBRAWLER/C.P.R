// : Implementation of Worst Fit method.
#include <bits/stdc++.h>
using namespace std;
void worstFit(vector<int>& blockSize, vector<int>& processSize)
{
vector<int> allocation(processSize.size(), -1);
for (int i = 0; i < processSize.size(); i++)
{
int wstIdx = -1;
for (int j = 0; j < blockSize.size(); j++)
{
if (blockSize[j] >= processSize[i])
{
if (wstIdx == -1)
wstIdx = j;
else if (blockSize[wstIdx] < blockSize[j])
wstIdx = j;
}
}
if (wstIdx != -1)
{
allocation[i] = wstIdx;
blockSize[wstIdx] -= processSize[i];
}
}
cout << "\nProcess No.\tProcess Size\tBlock no.\n";
for (int i = 0; i < processSize.size(); i++)
{
cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
if (allocation[i] != -1)
cout << allocation[i] + 1;
else
cout << "Not Allocated";
cout << endl;
}
}
int main()
{
int m, n;
cout << "Enter number of memory blocks: ";
cin >> m;
vector<int> blockSize(m);
cout << "Enter sizes of memory blocks:\n";
for(int i = 0; i < m; i++)
cin >> blockSize[i];
cout << "Enter number of processes: ";
cin >> n;
vector<int> processSize(n);
cout << "Enter sizes of processes:\n";
for(int i = 0; i < n; i++)
cin >> processSize[i];
worstFit(blockSize, processSize);
return 0;
}