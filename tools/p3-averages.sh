#!/bin/bash

for i in {1..50}
do 
	../octave/prob3.m | awk '/Time/ {print $2}' >> temp
done
cat temp | awk '{sum += $1} END {sum /= 50; print "Average: = " sum}'
rm -f temp