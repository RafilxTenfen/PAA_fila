#ifndef _fila_pilha_interface
#define _fila_pilha_interface

typedef struct Fila_Pilha *p_fila_pilha;

// alloca memoria para pilha
p_fila_pilha criaFilaPilha(int quantidade_dado_pilha, int tamanho_dado_pilha);

// libera a memoria ocupada da pilha
int destroiFilaPilha(p_fila_pilha pp);

// adiciona elemento a pilha
int insereFilaPilha(p_fila_pilha p, void *elemento);
/*
verificar se a fila existe
pegar o fim da fila sem desenfileirar
agora tenho a pilha
verificar se a pilha esta cheia
senão estiver cheia, empilha o novo elemento
Se estive cheia, criar nova pilha, adicionar elemento e enfileirar
*/

// remove elemento da fila pilha se for inserido  [100, 80, 2] [4, 10, 3]
// e removeFilaPilha foi invocado, deve retornar 2
void* removeFilaPilha(p_fila_pilha p);

// se for inserido  [100, 80, 2] [4, 10, 3]
// deve retornar o valor 2
void* topoFilaPilha(p_fila_pilha p);

#endif
