#!/bin/bash
#PBS -l nodes=1:intel:ppn=8, mem=64gb
#PBS -l walltime=7:00:00:00
#PBS -M ja.montana@uniandes.edu.co
#PBS -m abe
#PBS -N Ejercicio25
#PBS -j oe
#PBS -o joboutput.txt

module load anaconda/python2
make -f Makefilev1 clean
make -f Makefilev1
