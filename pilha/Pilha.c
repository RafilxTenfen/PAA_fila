#include <stdlib.h>
#include <string.h>

#include "Pilha_privado.h"

#define TRUE 1
#define FALSE 0

pPilha criaPilha(int tamanho_vetor, int tamanho_info) {
  pPilha pp = malloc(sizeof(struct Pilha));
  pp->tamanho_info = tamanho_info;
  pp->topo = 0;
  pp->tamanho_maximo = tamanho_vetor;
  pp->dados = malloc(pp->tamanho_info * pp->tamanho_maximo);
  return pp;
}

// libera a memoria ocupada da pilha
int destroiPilha(pPilha pp) {
  free(pp->dados);
  free(pp);
  return TRUE;
}

// adiciona elemento a pilha
int empilha(pPilha p, void* elemento) {
  if (cheia(p)) return FALSE;
  void* destination = p->dados + p->topo * p->tamanho_info;
  void* source = elemento;
  int size = p->tamanho_info;
  memcpy(destination, source, size);
  p->topo++;
  return TRUE;
}

// remove elemento da pilha
void* desempilha(pPilha p) {
  void* result = topo(p);
  p->topo--;
  return result;
}

// retorna o valor do topo
void* topo(pPilha p) {
  if (vaziaP(p)) return FALSE;
  void* destination = malloc(p->tamanho_info);
  void* source = p->dados + (p->topo - 1) * p->tamanho_info;
  int size = p->tamanho_info;
  memcpy(destination, source, size);
  return destination;
}

int vaziaP(pPilha stack) {
  if (stack->topo <= 0) {
    return TRUE;
  }
  return FALSE;
}

int cheia(pPilha stack) {
  if (stack->topo >= stack->tamanho_maximo)
    return TRUE;
  return FALSE;
}