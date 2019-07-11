## Desarrollo de ejercicios de capitulo 5

1. Escribe un programa que llame a fork (). Antes de llamar a fork (), haga que el proceso principal acceda a una variable (por ejemplo, x) y establezca su valor en algo (por ejemplo, 100). ¿Qué valor tiene la variable en el proceso hijo? ¿Qué sucede con la variable cuando tanto el hijo como el padre cambian el valor de x?

[p1.c](p1.c)

Rta/. Ocurre que el proceso hijo aun queda con la variable que tenia el proceso principal, sin embargo, cuando cambiamos la variable en cada proceso (padre e hijo), ocurre que se modifican las variables en cada caso que se le haya asignado, en el caso de hijo, la variable x cambio a 200 y en el caso de padre, la variable x cambio a 300

2. Escriba un programa que abra un archivo (con la llamada al sistema open ()) y luego llame a fork () para crear un nuevo proceso. ¿Pueden el niño y el padre acceder al descriptor de archivo devuelto por open ()? ¿Qué sucede cuando se escriben en el archivo simultáneamente, es decir, al mismo tiempo?

[p2.c](p2.c)

Rta/. Tanto como el hijo como el padre pueden acceder al archivo creado, que en el caso del programa, proceso padre escribe su parte de texto y tambien proceso hijo. Ocurre lo mismo cuando se realiza simultameamente.

3. Escribir otro programa utilizando fork (). El proceso hijo debe imprimir "hola"; El proceso padre debe imprimir "adiós". Debe intentar asegurarse de que el proceso hijo siempre se imprima primero; ¿Puedes hacer esto sin llamar a wait () en el padre?

[p3.c](p3.c)

Rta/. Se puede retrasar el proceso del padre empleado el uso de la funcion `sleep()` donde añadimos un numero que determina la cantidad de tiempo que realiza dicho retraso, pues con un segundo basta para que proceso hijo adelante su impresion antes que el padre.

4. Escriba un programa que llame a fork () y luego llame a algún tipo de exec () para ejecutar el programa / bin / ls. Vea si puede probar todas las variantes de exec (), incluyendo (en Linux) execl (), execle (), execlp (), execv (), execvp () y execvpe (). ¿Por qué crees que hay tantas variantes de la misma llamada básica?

[p4.c](p4.c)

Rta/. Todas las funciones reciben como primer argumento la ruta absoluta del archivo a ejecutar, sin embargo, la diferencia y variacion de este tipo de llamada esta en los demás argumentos:

-En unas cada uno de los siguientes argumentos (a partir del segundo) es una opción o parámetro que recibe el archivo ejecutable para su funcionamiento, si lo requiere, y el último argumento es NULL.
-En las demás el segundo argumento es un arreglo de caracteres, donde cada elemento del arreglo es una opción o parámetro que el archivo ejecutable requiere para funcionar, si lo requiere, y el último elemento es NULL.

5. Ahora escriba un programa que use wait () para esperar a que el proceso hijo finalice en el padre. ¿Qué espera wait()? ¿Qué pasa si usas wait() en el niño?

[p5.c](p5.c)

Rta/. En el programa, cuando se llama a wait espera a que otro proceso finalice su ejecucion antes. Si este es empleado en el proceso hijo, ocurre que la salida es -1, pues no hay un proceso existente antes que el de niño, es decir, por ende no hay un proceso a la espera para que se termine y sea emitida la señal; por lo que esta salida es representada como un error.

6. Escriba una ligera modificación del programa anterior, esta vez utilizando waitpid () en lugar de wait (). ¿Cuándo sería útil waitpid ()?

[p6.c](p6.c)

Rta/. `waitpid` seria util cuando se requiera un uso selectivo de procesos hijo para suspender la ejecucion hasta que el proceso especificado por el argumento `pid` cambie de estado. Sin embargo, `waitpid` espera sólo por la muerte de los hijos, pero este comportamiento es modificable mediante el parámetro `options`. 


7. Escriba un programa que cree un proceso secundario y, a continuación, cierre la salida estándar (STDOUT FILENO). ¿Qué sucede si el hijo llama a printf () para imprimir algunos resultados después de cerrar el descriptor?

[p7.c](p7.c)

Rta/. Cuando el hijo llama a `close(STDOUT_FILENO)` ocurre que las siguientes instrucciones de `printf` no se realicen. No lanza un error por existir la instruccion de impresion, sino que simplemente no la ejecuta y procede a seguir las siguientes instrucciones.





