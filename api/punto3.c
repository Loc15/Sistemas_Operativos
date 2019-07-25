#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

 int main(int argc, char *argv[]) {
 int nuevo;
 nuevo=fork();
 if (nuevo < 0){ printf("error\n");}
 else if (nuevo == 0){ printf("Hola\n");}
 else {
 sleep(5);
 printf("Adios\n");
 }
 return 0;
 }
