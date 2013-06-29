CC=gcc
CFLAGS=-Wall -Werror

all: p1 p2

p1:
	$(CC) $(CFLAGS) prob1.c -o sol1
p2:
	$(CC) $(CFLAGS) prob2.c -o sol2 -lm

clean:
	rm -f *.o sol*
