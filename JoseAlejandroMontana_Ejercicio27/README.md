Compilar algo con MPI
=====================
Para compilar el código corremos:
```console
mpicc Hello_world_MPI.c
```
Para correr el output desde distintos núcleos se usa
```console
Mpirun -np 2 a.out
```
Esto corre nuestro "a.out" sobre los distintos nodos que se le pida, en este caso de le piden 2 por medidor la bandera "-np"