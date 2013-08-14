#!/bin/bash

IAVG=0
MAVG=0
for i in {1..1000}
do
	./sol2 | grep "time:" > temp.fle
	IAVG=$(echo "$IAVG + $(awk '/Iterative/ {print $4}' temp.fle)" | bc)
	MAVG=$(echo "$MAVG + $(awk '/Multiplicative/ {print $4}' temp.fle)" | bc)
done

IAVG=$(echo "scale=6; $IAVG / 1000" | bc)
MAVG=$(echo "scale=6; $MAVG / 1000" | bc)

echo "Iterative average:      $IAVG"
echo "Multiplicative average: $MAVG"

rm temp.fle