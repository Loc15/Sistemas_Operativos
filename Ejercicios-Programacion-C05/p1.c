#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
int x;
x=100;
  
printf("hello world %d\n", x);
int rc = fork();
  
if (rc < 0) {
// fork failed
  fprintf(stderr, "fork failed\n");
  exit(1);
  
  } else if (rc == 0) {
  // child (new process)
  printf("hello, I am child %d\n", x);
  x=200;
  printf("hello, I am child %d\n", x);
  
  } else {
  // parent goes down this path (main)
  printf("hello, I am parent of %d\n", x);
  x=300;
  printf("hello, I am parent of %d\n", x);
  }
return 0;
}
