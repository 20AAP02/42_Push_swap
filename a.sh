#!/bin/bash
b=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
c=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
d=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
e=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
f=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
g=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
h=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
i=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
j=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
k=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
l=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
m=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
n=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
o=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
p=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
q=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
r=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
s=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
t=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
u=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
v=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
w=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
x=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
y=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
z=$(gcc *.c && arg=$(python3 rando.py 100); ./a.out $arg | awk '{print $2}')
sum=$(echo "$b + $c + $d + $e + $f + $g + $h + $i + $j + $k + $l + $m + $n + $o + $p + $q + $r + $s + $t + $u + $v + $w + $x + $y + $z" | bc)
avg=$(echo "$sum / 25" | bc)
printf "$avg\n"
