#!/bin/bash

sum=0
for i in `seq 1 1000`;
do
        if (( $i % 5 == 0 )) || (( $i % 3 == 0 ))  
        then
	  sum=$(( i + sum ))
        fi
	
done
echo $sum
