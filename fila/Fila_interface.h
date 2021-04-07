#ifndef _fila_interface
#define _fila_interface

typedef struct Fila *pFila;

// cria um fila e retorna um ponteiro para a fila
pFila criar(int tamanho_dados);

// enfileira um novo elemento ao fim da fila
int insere(pFila f, void *elemento);

// desinfileira o primeiro elemento da fila
void* remove(pFila f);

// destroi a fila liberando memoria
int destroi(pFila f);


#endif
