#ifndef _pilha_interface
#define _pilha_interface

typedef struct Pilha *pPilha;

pPilha criaPilha(int tamanho_vetor, int tamanho_info);
int destroiPilha(pPilha pp);
int empilha(pPilha p, void *elemento);
void* desempilha(pPilha p);
void* topoPilha(pPilha p);
void printPilha(pPilha p);

#endif
