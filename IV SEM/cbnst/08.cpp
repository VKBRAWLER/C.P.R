// 8. WAP to Integrate numerically using Trapezoidal rule.
#include <iostream>
#include <cmath>
using namespace std;
// Define the function to integrate
double f(double x) {
 return x * x; // Example: f(x) = x^2
}
// Function to calculate the integral using the Trapezoidal Rule
double trapezoidalRule(double a, double b, int n) {
 double h = (b - a) / n; // Calculate the width of each subinterval
 double sum = f(a) + f(b); // Add the first and last terms
 // Calculate the sum of the middle terms
 for (int i = 1; i < n; i++) {
 double x = a + i * h;
 sum += 2 * f(x);
 }
 // Apply the trapezoidal rule formula
 return (h / 2) * sum;
}
int main() {
 double a, b;
 int n;
 // Input the limits of integration and number of subintervals
 cout << "Enter the lower limit (a): ";
 cin >> a;
 cout << "Enter the upper limit (b): ";
 cin >> b;
 cout << "Enter the number of subintervals (n): ";
 cin >> n;
 // Calculate the integral
 double result = trapezoidalRule(a, b, n);
 // Display the result
 cout << "\nThe integral value using Trapezoidal Rule is: " << result << endl;
 return 0;
}