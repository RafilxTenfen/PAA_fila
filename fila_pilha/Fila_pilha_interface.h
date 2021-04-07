#ifndef _pilha_interface
#define _pilha_interface

typedef struct Fila_Pilha *p_fila_pilha;

// alloca memoria para pilha
p_fila_pilha criaFila(int tamanho_vetor, int tamanho_info);

// libera a memoria ocupada da pilha
int destroiPilha(p_fila_pilha pp);

// adiciona elemento a pilha
int insere(p_fila_pilha p, void *elemento);
/*
verificar se a fila existe
pegar o fim da fila sem desenfileirar
agora tenho a pilha
verificar se a pilha esta cheia
senão estiver cheia, empilha o novo elemento
Se estive cheia, criar nova pilha, adicionar elemento e enfileirar
*/

// remove elemento da pilha
void* removeFP(p_fila_pilha p);

// retorna o valor do topo
void* topo(p_fila_pilha p);

#endif
