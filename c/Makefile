CC=gcc
CFLAGS=-Wall -Werror

all: p1 p2 p3 p3 p4 runall

p1:
	$(CC) $(CFLAGS) prob1.c -o sol1
p2:
	$(CC) $(CFLAGS) prob2.c -o sol2 -lm
p3:	
	$(CC) $(CFLAGS) prob3.c -o sol3 -lm
p4: 
	$(CC) $(CFLAGS) prob4.c -o sol4 -lm

runall:
	rm -f runall.sh
	for file in sol*; do \
		echo "./$$file" >> runall.sh; \
	done
	chmod a+x runall.sh

clean:
	rm -f *.o sol* runall.sh
