CC=gcc
CFLAGS=-Wall -std=c99 -g

.PHONY: all clean

all: test

hash.o: hash.h hash.c

test: test.c hash.o

clean:
	rm *.o test
