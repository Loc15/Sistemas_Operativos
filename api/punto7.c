#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

 int main(int argc, char *argv[]) {
 int nuevo;
 nuevo=fork();
 if (nuevo < 0){ printf("error\n");}
 else if (nuevo == 0){ printf("SOY EL PROCESO HIJO/n"); close(STDOUT_FILENO); printf("ESTO NO DEBE IMPRIMIRSE/n");}
 else {
 printf("Hola\n");
 }
 return 0;
 }

