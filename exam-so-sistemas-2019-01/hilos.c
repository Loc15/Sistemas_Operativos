#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"
#include <unistd.h>

puerta var;
double v = 0;


void *operacion1(void *arg) {
    double z = 25;
    double y = 350;
    sleep(2);
    cerrar_puerta(var);
    v=z/y;
    abrir_puerta(var);
    return NULL;
}

void *operacion2(void *arg) {
    double x = 1250;
    cerrar_puerta(var);
    v=v*x;
    abrir_puerta(var);
    return NULL;
}

int main(int argc, char *argv[]) {

    crear_puerta(var);
    pthread_t p1, p2;
    Pthread_create(&p1, NULL, operacion1, NULL); 
    Pthread_create(&p2, NULL, operacion2, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("Resultado: %f\n", v);
    destruir_puerta(var);
    return 0;
}

