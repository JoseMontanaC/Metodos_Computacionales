g++ -std=c++11 cuenta2.cpp -o Main.x
carpetas=Part_*
for i in $carpetas
do
    cd $i
    archivos=*.txt
    echo "Empieza el analisis del tiempo de la particion" $i
    for j in $archivos
    do
    	../Main.x $j > tiempos.txt
    done
    # rm a.out
    cd ..
done
rm Main.x

# carpetas=Part_*
# for i in $carpetas
# do
#     git add ./$i/tiempos.txt
# done
