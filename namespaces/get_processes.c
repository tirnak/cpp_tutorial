#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  printf("PID: %ld\n", (long)getpid());
  printf("PPID: %ld\n", (long)getppid());
  return 0;
}
