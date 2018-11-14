#!/bin/bash
#PBS -l nodes=1:ppn=8,mem=2gb,walltime=00:10:00
#PBS -M ja.montana@uniandes.edu.co
#PBS -m abe
#PBS -N Ejercicio27

module load anaconda/python2 
cd $PBS_O_WORKDIR
mpicc Gauss.c -o gauss.x
mpirun -np 30 gauss.x 500 1 1
cat sample_* > Sampling.txt
python2 Read_data.py Sampling.txt 1 1
