LO QUE HACE EL PROGRAMA
=======================

1. Al Ejecutar el comando
	```console
	make -f Makefilev1
	```
Se corre compila el código [cuenta.cpp](./cuenta.cpp), el cual primero lee el archivo [Pi.txt](./Pi.txt), escribe en el archivo [conteo.txt](./conteo.txt) el numero de coincidencias de los patrones "1", "12", "123", "1234" y "12345" y los escribe en una columna, en el archivo [tiempo_total.txt](./tiempo_total.txt) se escribe el tiempo total que toma este algoritmo en hacer el conteo de estos patrones.


2. Se definió que el output en la salida estándar saliera a un archivo llamado [Tiempos.txt](./Tiempos.txt), sobre el cual se escribe en que tanto se está partiendo el archivo y que tanto tiempo toma en hacer las comparaciones para cada partición.

3. El archivo [Tiempos.txt](./Tiempos.txt) es leído por el programa [plot_times.py](./plot_times.py) para finalmente generar la gráfica de los tiempos de computo en función de la división del archivo.

Resultados del programa
=======================

Al ver las gráficas ![Grafica del tiempo](https://github.com/JoseMontanaC/Metodos_Computacionales/blob/master/JoseAlejandroMontana_Ejercicio26/Grafica_tiempo.pdf) y ![Gráfica del tiempo total](https://github.com/JoseMontanaC/Metodos_Computacionales/blob/master/JoseAlejandroMontana_Ejercicio26/Graf_tiempo_total.pdf) se ve en la primera que al parecer el tiempo promedio que toma una partición dada disminuye en función de esta partición, sin embargo vemos que de la segunda gráfica que el tiempo total que demora el algoritmo no es menor a medida que se aumenta la partición, con lo cual se encuentra que la partición ideal sería de 20, para así disminuir el tiempo de computo promedio y además conseguir que en total el algoritmo tome menos tiempo.
<img src="https://github.com/JoseMontanaC/Metodos_Computacionales/files/2564056/Graf_tiempo_total.pdf" width="45%"></img> <img src="https://github.com/JoseMontanaC/Metodos_Computacionales/files/2564057/Grafica_tiempo.pdf" width="45%"></img> 