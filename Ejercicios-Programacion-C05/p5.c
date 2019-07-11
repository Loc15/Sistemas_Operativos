#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int rc = fork();
  
  if (rc < 0) { // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
    
  } else if (rc == 0) { // child (new process)
    int wait_p = wait(NULL);
    printf("hello, I am child (pid:%d), y el valor de wait es: (wait_p:%d)\n", (int) getpid(), wait_p);
    
  } else { // parent goes down this path (main)
    printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
  }
return 0;
}
