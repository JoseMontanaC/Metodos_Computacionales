Programa en paralelo que calcula una integral e¡haciendo uso de MPI
===================================================================

1. Al correr el archivo [Torque_V1.sh](./Torque_V1.sh) 
	```console
	bash Torque_V1.sh
	```
Se compila el codigo [integrar.cpp](./integrar.cpp) usando el compilador de "mpic++", esto genera un ejecutable que se corre para una cantidad de puntos de ![ecuacion](https://latex.codecogs.com/gif.latex?N%3D%2010%2C%2010%5E%7B2%7D%2C%20%5Cdots%2C%2010%5E%7B10%7D)



2. Se definió que el output en la salida estándar saliera a un archivo llamado [Tiempos.txt](./Tiempos.txt), sobre el cual se escribe en que tanto se está partiendo el archivo y que tanto tiempo toma en hacer las comparaciones para cada partición.

3. El archivo [Tiempos.txt](./Tiempos.txt) es leído por el programa [plot_times.py](./plot_times.py) para finalmente generar la gráfica de los tiempos de computo en función de la división del archivo.

Resultados del programa
=======================

Al ver las gráficas [Grafica del tiempo](https://github.com/JoseMontanaC/Metodos_Computacionales/blob/master/JoseAlejandroMontana_Ejercicio26/Grafica_tiempo.png) y [Gráfica del tiempo total](https://github.com/JoseMontanaC/Metodos_Computacionales/blob/master/JoseAlejandroMontana_Ejercicio26/Graf_tiempo_total.png) se ve en la primera que al parecer el tiempo promedio que toma una partición dada disminuye en función de esta partición, sin embargo vemos que de la segunda gráfica que el tiempo total que demora el algoritmo no es menor a medida que se aumenta la partición, con lo cual se encuentra que la partición ideal sería de 20, para así disminuir el tiempo de computo promedio y además conseguir que en total el algoritmo tome menos tiempo.

![Grafica del tiempo](https://github.com/JoseMontanaC/Metodos_Computacionales/blob/master/JoseAlejandroMontana_Ejercicio26/Grafica_tiempo.png)


![Gráfica del tiempo total](https://github.com/JoseMontanaC/Metodos_Computacionales/blob/master/JoseAlejandroMontana_Ejercicio26/Graf_tiempo_total.png)
