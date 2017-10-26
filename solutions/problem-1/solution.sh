#!/bin/bash
for i in {1..999}; do (( $i % 3 == 0 || $i % 5 == 0 )) && let sum+=i; done
echo $sum
