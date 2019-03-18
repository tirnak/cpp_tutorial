#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static char child_stack[1048576];

static int child_fn(void* arg) {
  printf("From %s - PID: %ld\n", (char*) arg, (long)getpid());
  printf("From %s - Parent PID: %ld\n", (char*) arg, (long)getppid());
  return 0;
}

int main() {
  printf("From main() - PID: %ld\n", (long)getpid());
  printf("From main() - Parent PID: %ld\n", (long)getppid());

  printf("Create process within same namespace:\n");
  pid_t child_pid = clone(child_fn, child_stack+1048576, SIGCHLD, "same namespace");
  printf("PID of child with same namespace = %ld\n", (long)child_pid);

  waitpid(child_pid, NULL, 0);

  printf("Create process with a different namespace:\n");
  pid_t child_pid_new_ns = clone(child_fn, child_stack+1048576, CLONE_NEWPID | SIGCHLD, "new namespace");

  printf("PID of child with new namespace = %ld\n", (long)child_pid_new_ns);
  waitpid(child_pid_new_ns, NULL, 0);
  
  return 0;
}
