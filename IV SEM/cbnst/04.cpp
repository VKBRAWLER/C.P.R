// 4. WAP to find the roots of non-linear equation using Iteration method.
#include<bits/stdc++.h>
using namespace std;
double g(double x)
{
 return cbrt(x + 1); // Rearranged function x = g(x)
}
int main()
{
 double x0, x1;
 cout << "Enter the initial guess: ";
 cin >> x0;
 int i;
 for(i = 0; i < 10; i++) // Adjust the number of iterations or use tolerance
 {
 x1 = g(x0); // Fixed point iteration formula: x1 = g(x0)
 if(fabs(x1 - x0) < 1e-6) // If the difference is small enough, stop
 {
 cout << "Root is approximately: " << x1 << endl;
 return 0;
 }
 x0 = x1; // Update x0 for the next iteration
 }
 cout << "Root after iterations is approximately: " << x1 << endl;
 return 0;
}