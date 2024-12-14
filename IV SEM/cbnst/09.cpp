// 9. WAP to Integrate numerically using Simpson’s 1/3 rules.
#include <iostream>
#include <cmath>
using namespace std;
// Define the function to integrate
double f(double x) {
 return x * x; // Example: f(x) = x^2
}
// Function to calculate the integral using Simpson's 1/3 Rule
double simpsonsRule(double a, double b, int n) {
 // Check if n is even
 if (n % 2 != 0) {
 cout << "Error: Number of subintervals (n) must be even.\n";
 return -1;
 }
 double h = (b - a) / n; // Calculate the width of each subinterval
 double sum = f(a) + f(b); // Add the first and last terms
 // Calculate the sum of odd terms (4 * f(x_i))
 for (int i = 1; i < n; i += 2) {
 double x = a + i * h;
 sum += 4 * f(x);
 }
 // Calculate the sum of even terms (2 * f(x_i))
 for (int i = 2; i < n; i += 2) {
 double x = a + i * h;
 sum += 2 * f(x);
 }
 // Apply the Simpson's 1/3 Rule formula
 return (h / 3) * sum;
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
 double result = simpsonsRule(a, b, n);
 // Display the result if n is valid
 if (result != -1) {
 cout << "\nThe integral value using Simpson's 1/3 Rule is: " << result << endl;
 }
 return 0;
}