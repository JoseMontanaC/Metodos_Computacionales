LO QUE HACE EL PROGRAMA
=======================

1. Al Ejecutar el comando
	```console
	make -f Makefilev1
	```
Se corre compila el código [cuenta.cpp](./cuenta.cpp), el cual primero lee el archivo [Pi.txt](./Pi.txt), escribe en el archivo [conteo.txt](./conteo.txt) el numero de coincidencias de los patrones "1", "12", "123", "1234" y "12345" y los escribe en una columna, en el archivo [tiempo_total.txt](./tiempo_total.txt) se escribe el tiempo total que toma este algoritmo en hacer el conteo de estos patrones.


2. Se definió que el output en la salida estándar saliera a un archivo llamado [Tiempos.txt](./Tiempos.txt), sobre el cual se escribe en que tanto se está partiendo el archivo y que tanto tiempo toma en hacer las comparaciones para cada partición.

3. El archivo [Tiempos.txt](./Tiempos.txt) es leído por el programa [plot_times.py](./plot_times.py) para finalmente generar la gráfica de los tiempos de computo en función de la división del archivo.