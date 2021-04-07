#ifndef _pilha_interface
#define _pilha_interface

typedef struct Pilha *pPilha, **ppPilha;

// alloca memoria para pilha
ppPilha criaPilha(int tamanho_vetor, int tamanho_info);

// libera a memoria ocupada da pilha
int destroiPilha(ppPilha pp);

// adiciona elemento a pilha
int empilha(pPilha p, void *elemento);

// remove elemento da pilha
void* desempilha(pPilha p);

// retorna o valor do topo
void* topo(pPilha p);

#endif
