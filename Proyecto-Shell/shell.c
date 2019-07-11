#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include "cmd.h"


char prompt[] = "> ";


int main(int argc, char *argv[])
{
 
#define NCMD 5
char entrada[SIZE];  
int i;
char* listadecomandos[NCMD]={"clr","help", "pause", "quit", "pwd"};
int segundoplano=0;
int Stdout = dup(1);
int Stdin = dup(0);



while(1) 
	{
        close(1);
        dup(Stdout); 
        dup(Stdin); 
    intro();
	printf("%s", prompt);

	scanf("\n%[^\n]",entrada); 
	segundoplano=0;
	for(i=0;entrada[i] != '\0'; i++){
		if(entrada[i] == '&') {
					entrada[i] = '\0';
					segundoplano = 1;
					}
						}
for (i = 0; i < NCMD; i++)
    if(strcmp(entrada, listadecomandos[i])==0)
    {
        break;
        
    }
        
    switch (i) 
    { 
    case 0:  
        system("clear");
        break;
    case 1: 
        ayuda();
        break;
    case 2: 
        getchar();
        break;
    case 3: 
        exit(0);
        break;
    case 4:
        pwd();
        break;
        
    default:
        fun(entrada,segundoplano);
        break;
    } 
 
	}
	
return(0);
} 

