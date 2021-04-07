#ifndef _fila_interface
#define _fila_interface

#define SUCCESSO 0
#define ERRO 1

typedef struct Fila *fFila;

// cria um fila e retorna um ponteiro para a fila
fFila criar(int tamanho_dados);

// enfileira um novo elemento ao fim da fila
int insere(fFila f, void *elemento);

// desinfileira o primeiro elemento da fila
void* remove(fFila f);

// destroi a fila liberando memoria
int destroi(fFila f);


#endif
