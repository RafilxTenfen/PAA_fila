#ifndef _fila_interface
#define _fila_interface

#define SUCCESSO 0
#define ERRO 1

typedef struct Fila *fFila;

fFila criarFila(int tamanho_dados);
int enfileirar(fFila f, void *elemento);
void* desenfileira(fFila f);
int destroiFila(fFila f);
void* fimFila(fFila f);
void* inicioFila(fFila f);
void printFila(fFila f);

#endif
