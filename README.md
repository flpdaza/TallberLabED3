# TallberLabED3

Autores: Felipe Daza Cortes
         Miguel Galleguillos Nuñez
         
#Creacion de archivos
Para saber si existen los archivos csv debe revisar la carpeta archivos que esta dentro de la carpeta source, para hacer esto ejecutamos "cd source", luego ingresamos "cd archivos", cuando estemos situados en esta carpeta ejecutamos "ls" para ver si existen los archivos "servidores.csv" y "conexiones.csv" . En caso de no exitir y estando situados en esta misma carpeta de archivos ejecutar los siguientes comandos para crear los archivos
"g++ crearArchivos.cpp -o crearArchivos.exe" y luego "./crearArchivos.exe", luego podemos confirmar con "ls" si los archivos estan creados. Creados los archivos ya podemos empezar a trabajar con el programa principal.

#Ejecucion del programa
Para compilar el programa debemos estar situados en la carpeta source y ejecutamos el comando "g++ main.cpp -o main.exe" y luego "./main.exe" y desde aca se trabaja por consola.

El programa quisimos estructurarlo en 4 clases, llamadas "main.cpp" , "Grafo.h" , "NodoServidores.h" y "Conexiones.h", estas clases en conjunto trabajan para encontrar la ruta mas corta entre dos clientes a traves del algortimo Bellman-Ford en grafos con datos pedidos al usuario.

La aplicacion cuenta con un menu de 3 opciones las cuales son: 1-Mostrar conexiones por servidor y 2-Calcular la ruta y 3- Buscar ruta.

El algoritmo de Bellman-Ford es un algoritmo utilizado para encontrar los caminos más cortos desde un único origen a todos los demás nodos en un grafo ponderado, incluso si hay aristas con pesos negativos. El algoritmo también puede detectar ciclos negativos en el grafo.





