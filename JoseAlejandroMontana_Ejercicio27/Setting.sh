#!/bin/bash
#PBS -l nodes=1:ppn=8,mem=2gb,walltime=00:10:00
#PBS -M ja.montana@uniandes.edu.co
#PBS -m abe
#PBS -N Ejercicio27

cd $PBS_O_WORKDIR
make clean
make
