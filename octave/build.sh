#!/bin/sh

rm -f runall.sh

for file in prob*; do
	echo "octave -q ./$file" >> runall.sh
done	

chmod u+x runall.sh
