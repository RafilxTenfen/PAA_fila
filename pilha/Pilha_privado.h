#ifndef _pilha_privado
#define _pilha_privado

#include "Pilha_interface.h"

struct Pilha {
  int topo;
  int tamanho_vetor;
  int tamanho_info;
  void *dados;
};

int cheia(pPilha p);
int vazia(pPilha p);

#endif
