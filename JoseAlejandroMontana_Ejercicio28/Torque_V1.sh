#!/bin/bash
#PBS -l nodes=1:ppn=8,mem=1gb,walltime=00:10:00
#PBS -M ja.montana@uniandes.edu.co
#PBS -m abe
#PBS -N Ejercicio25

# module load anaconda/python2
# cd $PBS_O_WORKDIR
mpic++ integrar.cpp -o Integra.x
rm datos_*
p=10
mkdir Datos
cd Datos
for((ii=1;ii<=9;ii++))
do
    mpirun -np 2 ../Integra.x $p > datos_$ii.txt 
    potencia=$(echo 10 $p  | awk '{printf "%5d\n",$1*$2}')
    p=$potencia
    echo "hecho $ii"
done
cat datos_* > Datos.txt
cd ..
rm *.x
python2  Plot_error.py Datos/Datos.txt

# mpirun -np 2 Integra.x 100
