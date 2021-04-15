#ifndef _fila_pilha_interface
#define _fila_pilha_interface

typedef struct Fila_Pilha *p_fila_pilha;

p_fila_pilha criar(int quantidade_dado_pilha, int tamanho_dado_pilha);
int destruir(p_fila_pilha pp);
int insere(p_fila_pilha p, void *elemento);
void* retira(p_fila_pilha p);

#endif
