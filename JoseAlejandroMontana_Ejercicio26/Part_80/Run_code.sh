archivos=corte_*
g++ -std=c++11 ../Cuenta_to_file.cpp -o Main.x
len=$(ls corte_* | wc -l)
longitud=$(seq 1 1 $len)
if [ -d Tiempos ]
then
    rm -r Tiempos
    mkdir Tiempos
    cd Tiempos
else
    mkdir Tiempos
    cd Tiempos
fi

for ((kk=1;kk<=$len;kk++))
do
    arch="../corte_$kk.txt"
    ../Main.x $arch "tiempo_$kk.txt" &
done
tiempo=tiempo_*
cat $tiempo > Tiempos.txt
cd ..
rm Main.x


    # for ((kk=1;kk<=$len;kk++))
    # do   
    # done
    # mkdir Tiempos
    # cd Tiempos
    # ../Main.x $j  tiempos

