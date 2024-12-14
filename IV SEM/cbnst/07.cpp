// 7. WAP to interpolate numerically using Lagrange’s method.
#include <iostream>
using namespace std;
// Function to perform Lagrange Interpolation
double lagrangeInterpolation(double x[], double y[], int n, double xp) {
 double yp = 0; // Initial value of interpolated result
 // Loop through each term of the Lagrange formula
 for (int i = 0; i < n; i++) {
 double term = y[i];
 for (int j = 0; j < n; j++) {
 if (j != i) {
 term *= (xp - x[j]) / (x[i] - x[j]);
 }
 }
 yp += term; // Add term to final result
 }
 return yp;
}
int main() {
 int n;
 cout << "Enter the number of data points: ";
 cin >> n;
 double x[n], y[n];
 cout << "Enter the x and y values:\n";
 for (int i = 0; i < n; i++) {
 cout << "x[" << i << "]: ";
 cin >> x[i];
 cout << "y[" << i << "]: ";
 cin >> y[i];
 }
 double xp;
 cout << "Enter the x value to interpolate: ";
 cin >> xp;
 // Call the Lagrange interpolation function
 double yp = lagrangeInterpolation(x, y, n, xp);
 // Display the result
 cout << "\nInterpolated value at x = " << xp << " is " << yp << endl;
 return 0;
}