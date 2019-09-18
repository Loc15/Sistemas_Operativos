# Docker
# Preguntas

Que se debe configurar para que la maquina virtual se inicie con un linux de 64 bits?
R/:Se modifica en el vagrantfile, la linea  config.vm.box para que la maquina inicie con la imagen de un linux de 64 bits, ejemplo - config.vm.box = "ubuntu/xenial64"

Cree un alias en Bash que le permita contar cuantas imágenes de Docker tiene en su
computador.

El alias se crea de la siguiente manera:
alias nombre_alias='comando'   alias imagenes='docker images'

Qué archivos + directorios tiene este contenedor?
R/:Tiene los directorios bin   dev   etc   home  proc  root  sys   tmp   usr   var

¿Qué usuario es usted en ese momento?
R/:17298cb3d233

¿Qué sucede si ejecuta el comando ‘​ rm -rf /bin/*​ ’? ¿Qué comandos ya no puede
ejecutar?
R/:Se borarron los archivos ejecutables (o binarios) básicos del sistema y ya no se puede ejecutar comandos como ls, cd, cp, kill etc

Abra otra terminal y vuelva a correr el comando ‘​ docker run ​ -it busybox sh​ ’. El directorio‘​ /bin​ ’ tiene archivos? 
R/:Si, tiene los ejecutables basicos del sistema

Qué significa ese comando? docker run ​ -it ubuntu ​ / ​bin​ /  bash
R/:Es la ejecucion del docker de ubuntu junto al shell de este 

¿Qué significan:

 - -d​ ? Es un comando para iniciar un contenedor en detached mode
 - -P​ ? Asigna el puerto del contenedor a un puerto host aleatorio
 - -name static-site​ ? Se puso al contenedor el nombre de static-site​


#Hágalo usted mismo - Asciinema Videos

 - Vagrantfile [Vagrantfile](Vagrantfile)
 - Helloworld [Video](https://asciinema.org/a/m5gGgnMRG5fXhtKY5fyUduMSp)
 - Docker pull [Video](https://asciinema.org/a/sONsmWm0fdOU0V4F0wmQxFjK9)
 - Docker images [Video](https://asciinema.org/a/SnyvBql8qaX5uesoTPJrME4iQ)
 - Docker run [Video](https://asciinema.org/a/EIuhMjOpRb30cRTxcNWE0JgdW)
 - Docker ps [Video](https://asciinema.org/a/VfJxAbGxfKAxhOmmWPtwXGLIh)
 - Docker rm [Video](https://asciinema.org/a/1VUCjtMVeddd7kUIM3sgUGO4Z)
 - Docker stop [Video](https://asciinema.org/a/PIQiRC9FE0HAgYQ9Tn7gyTfNZ)
 - Docker start [Video](https://asciinema.org/a/n7mifcgjTwsUYkuWXYwv7grnS)
 - Docker attach [Video](https://asciinema.org/a/6NaTGzvm9o2twqgCsaHbhxMco)
 - Un sitio web estático [Video](https://asciinema.org/a/u71UVJTZzHSgYSHDrHiWwUgen)
 - Docker del aplicativo R [Video](https://asciinema.org/a/G5DngeKiNuxX3gCMBo7zB9Kat)
 - Creando su propio sitio web [Video](https://asciinema.org/a/qzOduBiHL2guZwjOK7n4TM3Nd)








