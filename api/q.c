#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

 int main(int argc, char *argv[]) {
 int rc = fork();
 if (rc < 0) {
 // fork failed
 fprintf(stderr, "fork failed\n");
 exit(1);
 } else if (rc == 0) {
 char *myargs[2];
 myargs[0] = strdup("ls"); // program: wc (word count)
 myargs[1] = NULL; // mark end of array
 execvp(myargs[0], myargs); // runs word count
 } else {
 int rc_wait = wait(NULL);
 printf("Adios\n");
 }
 return 0;
 }
