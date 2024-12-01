// parent process computes sum of even numbers and child process computes sum of odd numbers
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
  pid_t pid = fork();

  if (pid < 0) {
    cerr << "Fork failed" << endl;
    return 1;
  } else if (pid == 0) {
    // Child process
    int sum_odd = 0;
    for (int i = 1; i <= 100; i += 2) {
      sum_odd += i;
    }
    cout << "Sum of odd numbers: " << sum_odd << endl;
  } else {
    // Parent process
    int sum_even = 0;
    for (int i = 2; i <= 100; i += 2) {
      sum_even += i;
    }
    cout << "Sum of even numbers: " << sum_even << endl;
    wait(NULL); // Wait for child process to complete
  }

  return 0;
}