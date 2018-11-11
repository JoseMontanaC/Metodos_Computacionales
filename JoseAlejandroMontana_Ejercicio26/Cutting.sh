mkdir Part_10
cd Part_10
# longitud=$(wc -c "./Num.txt" | awk '{print $1}')
archivo="Num.txt"
longitud=$(wc -c ../$archivo | awk '{print $1}')
division=10
r=$(($longitud/$division))
# echo $r
for ((kk=0;kk<$division;kk++))
do
    initial=$(($kk*$r))
    final=$((($kk+1)*$r))
    cut -c$(($initial+1))-$(($final+1)) ../$archivo > corte_$(($kk+1)).txt
    # echo $(($initial+1)) $initial $final $(($final+1))
    # for ((ii=initial;ii<=final;ii++))
    # for ((ii=$(($kk*$r));ii<$((($kk+1)*$r));ii++))
    	# do
    	    # echo $(($ii+1)) $kk
    	# done	 
done


# cut -c1-10 pi.txt


