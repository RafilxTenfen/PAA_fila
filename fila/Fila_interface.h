#ifndef _fila_interface
#define _fila_interface

#define SUCCESSO 0
#define ERRO 1

typedef struct Fila *fFila;

// cria um fila e retorna um ponteiro para a fila
fFila criarFila(int tamanho_dados);

// enfileira um novo elemento ao fim da fila
int enfileirar(fFila f, void *elemento);

// desinfileira o primeiro elemento da fila
void* desenfileira(fFila f);

// destroi a fila liberando memoria
int destroiFila(fFila f);

// retorna o fim da fila sem desinfileirar
void* fimFila(fFila f);

// retorna o inicio da fila sem desinfileirar
void* inicioFila(fFila f);

void printFila(fFila f);

#endif
