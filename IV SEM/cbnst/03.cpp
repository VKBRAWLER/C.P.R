// 3. WAP to find the roots of non-linear equation using Newton’s Raphson method. 
#include<bits/stdc++.h>
using namespace std;
double fun(double x)
{
 return x*x*x - 4*x - 9;
}
double derivative(double x)
{
 return 3*x*x - 1;
}
int main()
{
 double x0, x1;
 cout << "Enter the initial guess: ";
 cin >> x0;
 int i;
 for(i = 0; i < 10; i++)
 {
 x1 = x0 - fun(x0)/derivative(x0);
 if(fun(x1) == 0) // If root is found
 {
 cout << "Exact root: " << x1 << endl;
 return 0;
 }
 x0 = x1; // Update x0 for next iteration
 }
 cout << "Root is approximately: " << x1 << endl;
 return 0;
}