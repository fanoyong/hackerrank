#!/bin/bash

read a
read b
if ((a>b))
then
    echo "X is greater than Y"
elif ((a==b))
then
    echo "X is equal to Y"
else
    echo "X is less than Y"
fi
