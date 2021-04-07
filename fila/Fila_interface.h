#ifndef _fila_interface
#define _fila_interface

#define SUCCESSO 0
#define ERRO 1

typedef struct Fila *pFila;

// cria um fila e retorna um ponteiro para a fila
pFila criar(int tamanho_dados);

// enfileira um novo elemento ao fim da fila
int insere(pFila f, void *elemento);

// desinfileira o primeiro elemento da fila
void* remove(pFila f);

// destroi a fila liberando memoria
void destroi(pFila f, int *resultado);


#endif
