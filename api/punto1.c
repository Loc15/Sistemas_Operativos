#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
 printf("nuevo proceso (pid:%d)\n", (int) getpid());
 int rc = fork();
 int x;
 x=100;
 if (rc < 0) {
 fprintf(stderr, "Fork falló\n");
 exit(1);
 }
 else if (rc == 0){
 printf("Soy el proceso hijo con PID = %d\n", (int) getpid());
 x=200;
 printf("el valor de la variable x es %d\n", x);
 }
 else { printf("Soy el proceso padre PID =  %d\n", (int) getpid());
 printf("valor de la variable x es %d\n", x);
 }
 
 return 0;
} 
