// Implimentation of FIFO
#include <bits/stdc++.h>
using namespace std;
int pageFaults(vector<int> pages, int capacity) {
  unordered_set<int> s;
  queue<int> indexes;
  int page_faults = 0;
  for (int i = 0; i < pages.size(); i++)
  {
    if (s.size() < capacity)
    {
      if (s.find(pages[i]) == s.end())
      {
        s.insert(pages[i]);
        page_faults++;
        indexes.push(pages[i]);
      }
    }
    else
    {
      if (s.find(pages[i]) == s.end())
      {
        int val = indexes.front();
        indexes.pop();
        s.erase(val);
        s.insert(pages[i]);
        indexes.push(pages[i]);
        page_faults++;
      }
    }
  }
  return page_faults;
}
int main()
{
  int s, capacity;
  cout << "Enter the number of pages: ";
  cin >> s;
  vector<int> pages(s);
  cout << "Enter pages: ";
  for (int i = 0; i < s; i++)
    cin >> pages[i];
  cout << "Enter frame capacity: ";
  cin >> capacity;
  int pf = pageFaults(pages, capacity); 
  int ph = pages.size() - pf;
  cout << "Total number of Page Faults = " << pf << endl;
  cout << "Total number of Page Hits = " << ph << endl;
  return 0;
}