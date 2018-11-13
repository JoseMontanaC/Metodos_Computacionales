#!/bin/bash
#PBS -l nodes=1:ppn=8,mem=1gb,walltime=00:10:00
#PBS -M ja.montana@uniandes.edu.co
#PBS -m abe
#PBS -N Ejercicio25

module load anaconda/python2
cd $PBS_O_WORKDIR
make -f Makefilev1 clean
make -f Makefilev1
