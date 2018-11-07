Como Correr el makefile
=======================

1. Ejecute el comando
	``` bash
		make -f Makefilev1
	```
2. Por defecto este makefile corre con los parámetros ![equation](https://latex.codecogs.com/gif.latex?N=5\times10^5), ![equation](http://latex.codecogs.com/gif.latex?%5Cmu%20%3D%200%2C%20%5Csigma%20%3D%201), si se quiere correr con otros nuevos parámetros, use el comando

	``` bash
		make -f Makefilev1 N="Val1" Mu = "Val2" Sigma= "Val3"
	
	```