// 10. WAP to Integrate numerically using Simpson’s 3/8 rules.
#include <iostream>
#include <cmath>
using namespace std;
// Define the function to integrate
double f(double x) {
 return x * x; // Example: f(x) = x^2
}
// Function to calculate the integral using Simpson's 3/8 Rule
double simpsons38Rule(double a, double b, int n) {
 // Check if n is a multiple of 3
 if (n % 3 != 0) {
 cout << "Error: Number of subintervals (n) must be a multiple of 3.\n";
 return -1;
 }
 double h = (b - a) / n; // Calculate the width of each subinterval
 double sum = f(a) + f(b); // Add the first and last terms
 // Calculate the sum of terms multiplied by 3 (odd and most middle points)
 for (int i = 1; i < n; i++) {
 double x = a + i * h;
 if (i % 3 == 0) {
 sum += 2 * f(x); // Every 3rd term gets multiplied by 2
 } else {
 sum += 3 * f(x); // All other terms get multiplied by 3
 }
 }
 // Apply the Simpson's 3/8 Rule formula
 return (3 * h / 8) * sum;
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
 double result = simpsons38Rule(a, b, n);
 // Display the result if n is valid
 if (result != -1) {
 cout << "\nThe integral value using Simpson's 3/8 Rule is: " << result << endl;
 }
 return 0;
}