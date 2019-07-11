#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
int archivo = open("nuevo_archivo.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
int rc = fork();

if (rc < 0) {
// fork failed
fprintf(stderr, "fork failed\n");
exit(1);
  
} else if (rc == 0) {
  const char * texto_hijo = "texto que se imprime por parte de hijo\n";
  printf("proceso hijo escribio el archivo\n");
  write(archivo, texto_hijo, strlen(texto_hijo));
  exit(0);
  } 
  
  else {
  wait(NULL);
  const char * texto_padre = "texto imprimido por parte de padre\n";
  printf("proceso padre escribio el archivo\n");
  write(archivo, texto_padre, strlen(texto_padre));
  }
  
return 0;
}
