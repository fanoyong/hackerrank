#!/bin/bash

read a
y="y"
Y="Y"
n="n"
N="N"
if [ $a = $y ]; then
    echo "YES"
elif [ $a = $Y ]; then
    echo "YES"
elif [ $a = $n ]; then
    echo "NO"
else
    echo "NO"
fi
