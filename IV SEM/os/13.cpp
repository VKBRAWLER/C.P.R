// : Implementation of Optimal Page Replacement.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool search(int key, vector<int>& fr) {
return find(fr.begin(), fr.end(), key) != fr.end();
}
int predict(vector<int>& pg, vector<int>& fr, int pn, int index) {
int res = -1, farthest = index;
for (int i = 0; i < fr.size(); i++) {
int j;
for (j = index; j < pn; j++) {
if (fr[i] == pg[j]) {
if (j > farthest) {
farthest = j;
res = i;
}
break;
}
}
if (j == pn)
return i;
}
return (res == -1) ? 0 : res;
}
void optimalPage(vector<int>& pg, int fn) {
vector<int> fr;
int hit = 0;
int pn = pg.size();
for (int i = 0; i < pn; i++) {
if (search(pg[i], fr)) {
hit++;
continue;
}
if (fr.size() < fn)
fr.push_back(pg[i]);
else {
int j = predict(pg, fr, pn, i + 1);
fr[j] = pg[i];
}
}
cout << "No. of hits = " << hit << endl;
cout << "No. of misses = " << pn - hit << endl;
}
int main() {
int n, fn;
cout << "Enter the number of frames: ";
cin >> fn;
cout << "Enter the number of pages: ";
cin >> n;
vector<int> pg(n);
cout << "Enter the pages: ";
for(int i = 0; i < n; i++)
cin >> pg[i];
optimalPage(pg, fn);
return 0;
}