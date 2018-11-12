g++ -std=c++11 cuenta2.cpp -o Main.x
carpetas=Part_*
for i in $carpetas
do
    cd $i
    rm Run_code.sh
    cp ../Run_code.sh ./
    rm tiempos.txt
    archivos=corte_*
    echo "Empieza el analisis del tiempo de la particion" $i
    for j in $archivos
    do
    	../Main.x $j >> tiempos.txt
	# echo "Haciendo el archivo" $j
    done
    bash Run_code.sh
    # rm a.out
    cd ..
done
rm Main.x


# carpetas=Part_*
# for i in $carpetas
# do
#     git add ./$i/tiempos.txt
# done
