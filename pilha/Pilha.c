#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Pilha_privado.h"

#define TRUE 1
#define FALSE 0

pPilha criaPilha(int tamanho_vetor, int tamanho_info) {
  pPilha pp = malloc(sizeof(struct Pilha));
  pp->tamanho_dados = tamanho_info;
  pp->topo = 0;
  pp->tamanho_maximo = tamanho_vetor;
  pp->dados = malloc(pp->tamanho_dados * pp->tamanho_maximo);
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
  if (cheia(p)) {
    return FALSE;
  }
  void* destination = p->dados + p->topo * p->tamanho_dados;
  void* source = elemento;
  int size = p->tamanho_dados;
  memcpy(destination, source, size);
  p->topo++;
  return TRUE;
}

// remove elemento da pilha
void* desempilha(pPilha p) {
  void* result = topoPilha(p);
  if (result != 0) p->topo--;
  return result;
}

// retorna o valor do topo
void* topoPilha(pPilha p) {
  if (vaziaP(p)) return FALSE;
  void* destination = malloc(p->tamanho_dados);
  void* source = p->dados + (p->topo - 1) * p->tamanho_dados;
  int size = p->tamanho_dados;
  memcpy(destination, source, size);
  return destination;
}

int vaziaP(pPilha p) {
  if (p->topo <= 0) {
    return TRUE;
  }
  return FALSE;
}

int cheia(pPilha p) {
  if (p == NULL) {
    return FALSE;
  }
  if (p->topo >= p->tamanho_maximo) {
    return TRUE;
  }
  return FALSE;
}

void printPilha(pPilha p) {
  printf("\nPRINT PILHA\nPointer %p\ntamanho_dados %d\ntopo %d\ntamanho_maximo %d", p, p->tamanho_dados, p->topo, p->tamanho_maximo);
}