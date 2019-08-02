# EXAMEN 1

Punto 1

Para realizar la primera parte del punto se hizo uso del comando ‘time’, que muestra el tiempo de ejecucion de un comando. El comando time muestra 3 tiempos pero es tomado el ‘real’ porque muestra el tiempo transcurrido entre la ejecucion y la finalizacion del comando. 
Informacion tomada: `https://es.wikipedia.org/wiki/Time_(Unix)`
Se ejecuta entonces el programa thread.c de la siguiente forma:
*`gcc -pthread thread.c -o thread` 
*`time ./thread 1000000`
la ejecucion dura 0m0,009s

La segunda modificacion al programa threads, nombrado threads2 se ejecuta igual que anterior: 
*`gcc -pthread thread2.c -o thread2` 
*`time ./thread2 1000000`
la ejecucion dura 0m0,129s

* [threads.c](threads.c)
* [threads2.c](threads2.c)

En la segunda modificacion del archivo threads.c la ejecucuion es más lenta  y esto se debe probablemente a que en la segunda ejecucion el programa tiene que abrir y la puerta cada vez que aumenta el valor de la variable counter, mientras que en la primera ejecucion solo se cierra la puerta antes de iniciar el ciclo y una vez finalizado este, la puerta se abre

Punto 2

* [hilos.c](hilos.c)

punto 3

* [env.c](env.c)
