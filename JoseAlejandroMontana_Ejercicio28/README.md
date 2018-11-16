Programa en paralelo que calcula una integral Haciendo uso de MPI
===================================================================

1. Al correr el archivo [Torque_V1.sh](./Torque_V1.sh) 

	```console
	bash Torque_V1.sh
	```

Se compila el codigo [integrar.cpp](./integrar.cpp) usando el compilador de "mpic++", esto genera un ejecutable que se corre para una cantidad de puntos de ![ecuacion](https://latex.codecogs.com/gif.latex?N%3D%2010%2C%2010%5E%7B2%7D%2C%20%5Cdots%2C%2010%5E%7B9%7D), esto genera 10 archivos distintos que luego son unidos y se concatenan en el archivo (Datos.txt)[./Datos.txt].

Por ultimo el programa [Plot_error.py](./Plot_error.py) se encarga de graficar lo que que está en el archivo de [Datos.txt](./Datos.txt).

2. El archivo [Torque_V2.sh](./Torque_V2.sh) se corre como

	```console
	qsub Torque_V2.sh
	```

Este archivo es para ejecutar sólo en el cluster y corre 20 "MPI tasks" mientras que la versión 1 corre en mi computador y corre con 2 "MPI tasks".

Resultados del programa
=======================
Este programa Calcula la siguiente integral:
<p align="center">
<img src="https://latex.codecogs.com/gif.latex?%5Cint_0%5E1dx_1%5Cint_0%5E1dx_2%20%5Cdots%20%5Cint_0%5E1dx_%7B10%7D%20%5Cleft%28%20x_1&plus;x_2&plus;%5Cdots&plus;x_%7B10%7D%5Cright%20%29%5E%7B2%7D" alt="Ecuacion"/>
</p>

Por medio del método de integrales por Montecarlo.

Al ver la gráficas [Grafica del error](https://github.com/JoseMontanaC/Metodos_Computacionales/blob/master/JoseAlejandroMontana_Ejercicio28/Error.pdf) se tiene que el método parece estar funcionando a la perfección y como es de esperarse, el porcentaje de error disminuye en función del numero de puntos utilizado.

<p align="center">
<img src="https://github.com/JoseMontanaC/Metodos_Computacionales/blob/master/JoseAlejandroMontana_Ejercicio28/Error.png" alt="Grafica de error"/>
</p>

