// Implimentation of orphan and zombie process
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

void createOrphanProcess() {
  pid_t pid = fork();
  if (pid > 0) {
    // Parent process
    cout << "Parent process exiting, PID: " << getpid() << endl;
  } else if (pid == 0) {
    // Child process
    sleep(5); // Sleep to ensure parent exits first
    cout << "Orphan process, PID: " << getpid() << ", Parent PID: " << getppid() << endl;
  } else {
    cerr << "Fork failed" << endl;
  }
}

void createZombieProcess() {
  pid_t pid = fork();
  if (pid > 0) {
    // Parent process
    sleep(5); // Sleep to keep parent alive
    cout << "Parent process, PID: " << getpid() << endl;
  } else if (pid == 0) {
    // Child process
    cout << "Child process exiting, PID: " << getpid() << endl;
    _exit(0); // Exit without cleaning up
  } else {
    cerr << "Fork failed" << endl;
  }
}

int main() {
  cout << "Creating orphan process..." << endl;
  createOrphanProcess();
  sleep(10); // Wait to observe orphan process

  cout << "Creating zombie process..." << endl;
  createZombieProcess();
  sleep(10); // Wait to observe zombie process

  return 0;
}