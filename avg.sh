#!/bin/bash
sum=0
i=0
while [ $i -lt 28 ]
do
	sum=`expr $sum + $(gcc *.c && arg=$(python3 rando.py 500); ./a.out $arg | awk '{print $4}')`
	((i++))
done
sum=`expr $sum / 28`
echo $sum
