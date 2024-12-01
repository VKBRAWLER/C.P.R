// implementation of pipe()
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

int main() {
  int pipefd[2];
  pid_t cpid;
  char buf;

  if (pipe(pipefd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  cpid = fork();
  if (cpid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (cpid == 0) {    /* Child reads from pipe */
    close(pipefd[1]);          /* Close unused write end */

    while (read(pipefd[0], &buf, 1) > 0)
      write(STDOUT_FILENO, &buf, 1);

    write(STDOUT_FILENO, "\n", 1);
    close(pipefd[0]);
    _exit(EXIT_SUCCESS);

  } else {            /* Parent writes to pipe */
    close(pipefd[0]);          /* Close unused read end */
    const char *msg = "Hello from parent";
    write(pipefd[1], msg, strlen(msg));
    close(pipefd[1]);          /* Reader will see EOF */
    wait(NULL);                /* Wait for child */
    exit(EXIT_SUCCESS);
  }
}