#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *archivo = fopen("texto.txt","r"); //Asigna esta region de memoria para el archivo, abrir, nombre del archivo y modo lectura
	if (archivo == NULL)
	{
	printf("Error al abrir el archivo\n");
	return 1;
    }
    
    int posicion;
 
	fseek(archivo, -2, SEEK_END);  //(Nombre de la region de memoria, posiciones a movernos, cuenta desde el final)
	posicion = ftell(archivo);
	printf( "En la posición %d está la letra %c.\n", posicion, getc(archivo) );
	

	fclose(archivo);
	return 0;

}