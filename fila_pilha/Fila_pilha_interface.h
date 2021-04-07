#ifndef _pilha_interface
#define _pilha_interface

#include "Fila_interface.h"

typedef struct Fila *fFila;

// alloca memoria para pilha
fFila criaFila(int tamanho_vetor, int tamanho_info);

// libera a memoria ocupada da pilha
int destroiPilha(fFila pp);

// adiciona elemento a pilha
int empilha(fFila p, void *elemento);

// remove elemento da pilha
void* desempilha(fFila p);

// retorna o valor do topo
void* topo(fFila p);

#endif
