archivo="Pi.txt"
for i in $(seq 10 10 100)
do
    rm -r Part_$i
    mkdir Part_$i
    cd Part_$i
    longitud=$(wc -c ../$archivo | awk '{print $1}')
    division=$i
    r=$(($longitud/$division))
    for ((kk=0;kk<$division;kk++))
    do
	 initial=$(echo $kk $r 0.8 | awk '{printf "%5d\n",$1*($2+$3)}')
	 #Imprime como en C
	 final=$(echo $r $kk 0.8 1 | awk '{printf "%5d\n",($2+$4)*($3+$1)}')
	 cut -c$(($initial+1))-$final ../$archivo > corte_$(($kk+1)).txt
	 # echo $(($initial+1)) $final
	 # echo "-----------------------------"
    done
    echo "Done doing the " $i " Partition"
    cd ..
done

# rm -r Part_10
# mkdir Part_10
# cd Part_10
# archivo="Pi.txt"
# longitud=$(wc -c ../$archivo | awk '{print $1}')
# division=10
# r=$(($longitud/$division))

# for ((kk=0;kk<$division;kk++))
# do 
#     initial=$(echo $kk $r 0.8 | awk '{printf "%5d\n",$1*($2+$3)}')
#     #Imprime como en C
#     final=$(echo $r $kk 0.8 1 | awk '{printf "%5d\n",($2+$4)*($3+$1)}')
#     cut -c$(($initial+1))-$final ../$archivo > corte_$(($kk+1)).txt
#     echo $(($initial+1)) $final
#     echo "-----------------------------"
# done



# -----------------------------------------------------

# longitud=$(wc -c "./Num.txt" | awk '{print $1}')
# echo $r

 # more=$(echo "scale=4; 0.8*($kk+1)" | bc)
    # initial=$(echo $ $kk 1 | awk '{printf "%5d\n",$1*($2+$3)}')
    # initial=$(($longitud/$division*$kk))
    # final=$(($longitud/$division*($kk+1)))
    # initial=$(($kk*$r))
    # final=$((($kk+1)*$r))
    
    # echo $more $final | awk '{printf "%5.1d\n",($1+$2)}'
    # echo $(($initial+1)) $(($final+1))
    # for ((ii=initial;ii<=final;ii++))
    # for ((ii=$(($kk*$r));ii<$((($kk+1)*$r));ii++))
    	# do
    	    # echo $(($ii+1)) $kk
    	# done	 


# cut -c1-10 pi.txt


