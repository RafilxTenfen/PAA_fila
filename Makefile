# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -O3

default: main

main: main.c
	$(CC) $(CFLAGS) main.c -o main

clean:
	rm -f main *.o core a.out *.*~ Makefile~

all: main