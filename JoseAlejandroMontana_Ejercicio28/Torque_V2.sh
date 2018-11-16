#!/bin/bash
#PBS -l nodes=1:ppn=8,mem=1gb,walltime=00:10:00
#PBS -M ja.montana@uniandes.edu.co
#PBS -m abe
#PBS -N Ejercicio25

module load anaconda/python2
cd $PBS_O_WORKDIR
mpic++ integrar.cpp -o Integra.x
if [ -d Datos ]
then
    rm -r Datos
    mkdir Datos
    cd Datos
else
    mkdir Datos
    cd Datos
fi

p=10
for((ii=1;ii<=9;ii++))
do
    mpirun -np 20 ../Integra.x $p > datos_$ii.txt 
    potencia=$(echo 10 $p  | awk '{printf "%5d\n",$1*$2}')
    p=$potencia
done
cat datos_* > Datos.txt
cd ..
rm *.x
python2  Plot_error.py Datos/Datos.txt

