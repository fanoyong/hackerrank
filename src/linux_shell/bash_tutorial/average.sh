#!/bin/bash

read N
SUM=0
for i in $(seq 1 1 $N)
do
    read a
    SUM=$(($SUM+$a))
done
awk "BEGIN {printf \"%.3f\n\", $SUM / $N}"

