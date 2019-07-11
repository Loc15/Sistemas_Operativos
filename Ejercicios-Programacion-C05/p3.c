#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
int rc = fork();
  
if (rc < 0) {
  // fork failed
  fprintf(stderr, "fork failed\n");
  exit(1);
  
  } else if (rc == 0) {
  // child (new process)
  printf("hola\n");
  }
  
  else {
  // parent process
  sleep(1);
  printf("adios\n");
  }
  
return 0;
}
