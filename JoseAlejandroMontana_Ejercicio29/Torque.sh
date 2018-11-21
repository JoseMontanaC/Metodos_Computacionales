#!/bin/bash
#PBS -l nodes=1:ppn=8,mem=1gb,walltime=00:10:00
#PBS -M ja.montana@uniandes.edu.co
#PBS -m abe
#PBS -N Ejercicio28

# module load anaconda/python2
# cd $PBS_O_WORKDIR
gcc-8 -fopenmp Helloworld.c -o Hello.x
./Hello.x
rm *.x
rm *.txt
gcc Non_linear_advection.c -o Non_linear.x
./Non_linear.x
python Graficar.py
rm *.x
