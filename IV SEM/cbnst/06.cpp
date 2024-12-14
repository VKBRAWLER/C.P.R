// 6. WAP to interpolate numerically using Newton’s backward difference method.
#include <iostream>
#include <iomanip>
using namespace std;
// Function to calculate factorial
int factorial(int n) {
 int fact = 1;
 for (int i = 2; i <= n; i++) {
 fact *= i;
 }
 return fact;
}
int main() {
 int n;
 cout << "Enter the number of data points: ";
 cin >> n;
 double x[n], y[n][n]; // y is the backward difference table
 // Input data points
 cout << "Enter the x and y values:\n";
 for (int i = 0; i < n; i++) {
 cout << "x[" << i << "]: ";
 cin >> x[i];
 cout << "y[" << i << "]: ";
 cin >> y[i][0];
 }
 // Calculate the backward difference table
 for (int j = 1; j < n; j++) {
 for (int i = n - 1; i >= j; i--) {
 y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
 }
 }
 // Display the backward difference table
 cout << "\nBackward Difference Table:\n";
 for (int i = 0; i < n; i++) {
 cout << setw(10) << x[i];
 for (int j = 0; j <= i; j++) {
 cout << setw(10) << y[i][j];
 }
 cout << endl;
 }
 double xp;
 cout << "\nEnter the x value to interpolate: ";
 cin >> xp;
 // Newton Backward Interpolation
 double h = x[1] - x[0]; // Assuming equal spacing
 double u = (xp - x[n - 1]) / h;
 double yp = y[n - 1][0]; // Initial value of interpolated result
 for (int i = 1; i < n; i++) {
 double term = y[n - 1][i];
 for (int j = 1; j <= i; j++) {
 term *= (u + j - 1);
 }
 term /= factorial(i);
 yp += term;
 }
 // Display the result
 cout << "\nInterpolated value at x = " << xp << " is " << yp << endl;
 return 0;
}