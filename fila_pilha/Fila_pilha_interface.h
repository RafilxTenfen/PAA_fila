#ifndef _pilha_interface
#define _pilha_interface

#include "Fila_interface.h"

typedef struct Fila_Pilha *fp;

// alloca memoria para pilha
fFila criaFila(int tamanho_vetor, int tamanho_info);

// libera a memoria ocupada da pilha
int destroiPilha(fFila pp);

// adiciona elemento a pilha
int insere(fp p, void *elemento);
/*
verificar se a fila existe
pegar o fim da fila sem desenfileirar
agora tenho a pilha
verificar se a pilha esta cheia
senão estiver cheia, empilha o novo elemento
Se estive cheia, criar nova pilha, adicionar elemento e enfileirar
*/

// remove elemento da pilha
void* remove(fFila p);

// retorna o valor do topo
void* topo(fFila p);

#endif
