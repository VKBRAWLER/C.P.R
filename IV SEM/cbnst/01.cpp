// 1. WAP to find the roots of non-linear equation using Bisection method. 
#include<bits/stdc++.h>
using namespace std;
double fun(double x)
{
 return x*x*x - 4*x - 9;
}
int main()
{
 double x0, x1, x2;
 cout << "Enter the interval for your function: ";
 cin >> x0 >> x1;
 if(fun(x0) * fun(x1) > 0) {
 cout << "No root in this interval." << endl;
 return 0;
 }
 int i;
 for(i = 0; i < 10; i++)
 {
 x2 = (x0 + x1) / 2;
 if(fun(x2) == 0)
 {
 cout << "Exact root: " << x2 << endl;
 return 0;
 }
 else if(fun(x0) * fun(x2) < 0)
 {
 x1 = x2; // Root lies in left subinterval
 }
 else
 {
 x0 = x2; // Root lies in right subinterval
 }
 }
 cout << "Root is approximately: " << x2 << endl;
 return 0;
}