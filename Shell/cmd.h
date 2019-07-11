#define SIZE 80



void fun(char entrada[SIZE], int segundoplano);
void trasladar_in(char entrada[SIZE]);
void trasladar_out(char entrada[SIZE]);
void tuberias(char* comando[SIZE], char* comando2[SIZE]);
void run(char* comando[SIZE], int segundoplano);

void intro()
{
	char usuario[1204] = "";
	gethostname(usuario, sizeof(usuario));
	printf("%s@%s:", getenv("LOGNAME"), usuario);
}

void ayuda() //FUNCIONA
{ 
    puts("\nInformacion de ayuda sobre el shell"
        "\n>help = ayuda"
        "\n>clr = limpiar pantalla"
        "\n>quit = salir del shell"
        "\n>pause = congelar el shell"
        "\n>echo = mostar en pantalla comentarios"
        "\n>pwd = Directorio actual\n");  
} 



void pwd() //FUNCIONA
{
	char path[1024]; 
    getcwd(path, sizeof(path)); 
    printf("Directorio actual: %s\n", path); 
}


void fun(char entrada[SIZE], int segundoplano)
{ 

int i;
int j;
int k;
int tuberia;

char comandoInd[SIZE][SIZE]; 				
char comandoInd2[SIZE][SIZE];

char fichero[SIZE];
char ingreso[SIZE];

char *comando[SIZE]; 
char *comando2[SIZE];
int ejecutar=0;

comando[0] = NULL;					
comando2[0] = NULL;
tuberia = 0;

	 	k = 0;
	    i = 0;

		while(entrada[i] != '\0' && entrada[i] != '|' && entrada[i] != '>'){ 
					 for(j=0; entrada[i] != ' ' && entrada[i] != '\0' && entrada[i] != '|'  && entrada[i] != '>' && entrada[i] != '<';j++) { 
								comandoInd[k][j] = entrada[i];
								i++;}

					
					 if (entrada[i] == ' ') i++;

					
					comandoInd[k][j] = '\0';

					
					comando[k] = comandoInd[k];
					k++;
					if (entrada[i] == '<') { 
						i++;
						if (entrada[i] != ' ') ejecutar=1;
						else { i++;
							for(j=0; entrada[i] != '\0' && entrada[i] != ' ' && entrada [i] != '|' && entrada [i] != '>'; j++){
								ingreso[j] = entrada[i];
								i++;
									}
							ingreso[j] = '\0';
							if (entrada[i] != '\0') i++;
							trasladar_in(ingreso);
							}
						}
					
					} 

		comando[k] = NULL;

		if (entrada[i] == '|') {
			k=0;
			i++;
			if (entrada[i] != ' ') ejecutar=1;
			else { 
			i++;
			tuberia = 1;
			while(entrada[i] != '\0' && entrada[i] != '>'){	 
					for(j=0; entrada[i] != ' ' && entrada[i] != '\0' && entrada[i] != '>';j++) {
								comandoInd2[k][j] = entrada[i];
								i++;}
					if (entrada[i] == ' ' ) i++;
			
					comandoInd2[k][j] = '\0';
					comando2[k] = comandoInd2[k];
					k++;
				}
			comando2[k] = NULL;
			}		
		} 

		if (entrada[i] == '>') {
					i++;
					if (entrada[i] != ' ') ejecutar=1;
					else {
					i++;
					for(j=0; entrada[i] != '\0';j++) {
								fichero[j] = entrada[i];
								i++;}
					fichero[j] = '\0';
					trasladar_out(fichero);	
					}
		}
		
		if(ejecutar == 0) {
					if (tuberia==0) run(comando,segundoplano);
			
					else tuberias(comando,comando2);
				  }
		else printf("error");
		
}


void run(char* comando[SIZE],int segundoplano)

{
	int estado=0;
	pid_t hijo; 
	hijo=fork();
if (hijo==-1) printf("No se ha podido crear el proceso"); 
else if (hijo==0) {
			execvp(comando[0],comando);
			perror("error");
			exit(estado);
		   }
else  { 
		if (segundoplano == 0) hijo=wait(&estado);
		}

}


void trasladar_in(char entrada[SIZE])

{ 
  char *puntero;
  int fd;  
  puntero = entrada; 
  fd = open (puntero,O_RDONLY); 
  close (0); 	
  dup(fd);	
  

}

void trasladar_out(char entrada[SIZE])

{ 
  char *puntero;
  puntero = entrada; 
  close (1); 		
  open (puntero,O_CREAT | O_WRONLY,0777); 

} 




void tuberias(char* comando[SIZE], char* comando2[SIZE])

{ 
  int fd[2],estado;
	pid_t hijo; 
	hijo=fork();
	

	if (hijo==-1) printf("No se ha podido crear el proceso"); 
	else if (hijo==0) {
		   pipe(&fd[0]);
   			if (fork()!=0) {
      				close(fd[0]); 
      				close(1);
      				dup(fd[1]); 
      				close(fd[1]);
      				execvp(comando[0],comando);
   				}
   			else {
      				close(fd[1]);
      				close(0);
      				dup(fd[0]);
      				close(fd[0]);
     				execvp(comando2[0],comando2);
      
  				 }
		   }
	else  hijo=wait(&estado);
} 


