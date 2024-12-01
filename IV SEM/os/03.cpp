// demonstration of wait()
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
int main() {
  pid_t pid = fork();

  if (pid < 0) {
    cerr << "Fork failed" << endl;
    return 1;
  } else if (pid == 0) {
    // Child process
    cout << "Child process: PID = " << getpid() << endl;
    sleep(2); // Simulate some work in the child process
    cout << "Child process exiting" << endl;
    return 0;
  } else {
    // Parent process
    cout << "Parent process: PID = " << getpid() << endl;
    int status;
    wait(&status); // Wait for the child process to complete
    cout << "Child process completed with status: " << status << endl;
  }

  return 0;
}