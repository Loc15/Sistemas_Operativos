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
    
    int x = -2;

	fseek(archivo, x, SEEK_END); //(Nombre de la region de memoria, posiciones a movernos, cuenta desde el final)
	printf("%c", fgetc(archivo));

	x = x-1;
	while(ftell(archivo)!=1){
		fseek(archivo, x, SEEK_END);
		printf("%c", fgetc(archivo));
		x = x-1;
	}

	fclose(archivo);
	
	return 0;

}