carpetas=Part_*
for i in $carpetas
do
    cd $i
    archivos=*.txt
    echo "Empieza el analisis del tiempo de la particion" $i
    for j in $archivos
    do
	g++ ../cuenta2.cpp
	./a.out $j > tiempos.txt
    done
    cd ..
done
