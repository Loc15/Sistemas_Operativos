#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
 FILE *archivo = fopen("file.txt", "w");
 if (archivo == NULL){
 printf("Error al abrir el archivo\n");
 return 1; 
 }
 int nuevo;
 nuevo=fork();
 if (nuevo < 0){ printf("Error al craer el proceso\n");}
 else if (nuevo == 0){
 fputs("Modificacion por parte del hijo", archivo);
 }
 else {
 wait(NULL); 
 fputs("Moficacion por parte del padre\n", archivo);}
 fclose(archivo);
 return 0;
}

