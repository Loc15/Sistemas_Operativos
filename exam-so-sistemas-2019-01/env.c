#include <stdio.h>
#include <string.h>

char entrada[50];

int main ()
{
  scanf("\n%[^\n]",entrada);

  FILE *archivo = fopen("entrada","r");
	if (archivo == NULL)
	{
	printf("Error al abrir el archivo\n");
	return 1;
 
  char string[50];
  char *p;
  p = strtok (string,",:");
  while (p!= NULL)
  {
    printf ("%s\n",p);
    p = strtok (NULL, ",:");
  }
  return 0;
}
