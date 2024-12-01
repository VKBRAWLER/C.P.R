// demonstrate the fork() system call
#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
  pid_t pid = fork();

  if (pid < 0) {
    cerr << "Fork failed" << endl;
    return 1;
  } else if (pid == 0) {
    cout << "This is the child process. PID: " << getpid() << endl;
  } else {
    cout << "This is the parent process. PID: " << getpid() << ", Child PID: " << pid << endl;
  }

  return 0;
}