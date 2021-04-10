# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -03 gcc version
CFLAGS  = -g -Wall -O3

default: main

Fila.o: fila/Fila.c fila/Fila_interface.h fila/Fila_privado.h
	$(CC) $(CFLAGS) -c fila/Fila.c -o Fila.o

Pilha.o: pilha/Pilha.c pilha/Pilha_interface.h pilha/Pilha_privado.h
	$(CC) $(CFLAGS) -c pilha/Pilha.c -o Pilha.o

Fila_Pilha.o: fila_pilha/Fila_pilha.c fila_pilha/Fila_pilha_interface.h fila_pilha/Fila_pilha_privado.h
	$(CC) $(CFLAGS) -c fila_pilha/Fila_pilha.c -o Fila_pilha.o

main: main.c Fila.o Pilha.o Fila_Pilha.o
	$(CC) $(CFLAGS) main.c Fila.o Pilha.o Fila_pilha.o -o main

run: clean main
	./main

clean:
	rm -f main *.o core a.out *.*~ Makefile~

all: main