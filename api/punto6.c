#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

 int main(int argc, char *argv[]) {
 int nuevo;
 nuevo=fork();
 if (nuevo < 0){ printf("error\n");}
 else if (nuevo == 0){ int estado; waitpid(nuevo,&estado,0); printf("EL PADRE HA FINALIZADO/n");}
 else {
 printf("Hola\n");
 }
 return 0;
 }

