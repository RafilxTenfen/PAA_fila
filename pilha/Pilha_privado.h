#ifndef _pilha_privado
#define _pilha_privado

#include "Pilha_interface.h"

struct Pilha {
  int topo;
  int tamanho_maximo;
  int tamanho_dados;
  void *dados;
};

int cheia(pPilha p);
int vaziaP(pPilha p);

#endif
