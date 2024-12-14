// 5. WAP to interpolate numerically using Newton’s forward difference method.
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
 double x[n], y[n][n]; // y is the forward difference table
 // Input data points
 cout << "Enter the x and y values:\n";
 for (int i = 0; i < n; i++) {
 cout << "x[" << i << "]: ";
 cin >> x[i];
 cout << "y[" << i << "]: ";
 cin >> y[i][0];
 }
 // Calculate the forward difference table
 for (int j = 1; j < n; j++) {
 for (int i = 0; i < n - j; i++) {
 y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
 }
 }
 // Display the forward difference table
 cout << "\nForward Difference Table:\n";
 for (int i = 0; i < n; i++) {
 cout << setw(10) << x[i];
 for (int j = 0; j < n - i; j++) {
 cout << setw(10) << y[i][j];
 }
 cout << endl;
 }
 double xp;
 cout << "\nEnter the x value to interpolate: ";
 cin >> xp;
 // Newton Forward Interpolation
 double h = x[1] - x[0]; // Assuming equal spacing
 double u = (xp - x[0]) / h;
 double yp = y[0][0]; // Initial value of interpolated result
 for (int i = 1; i < n; i++) {
 double term = y[0][i];
 for (int j = 0; j < i; j++) {
 term *= (u - j);
 }
 term /= factorial(i);
 yp += term;
 }
 // Display the result
 cout << "\nInterpolated value at x = " << xp << " is " << yp << endl;
 return 0;
}