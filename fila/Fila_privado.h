#ifndef _fila_privado
#define _fila_privado

#include "Fila_interface.h"

typedef struct NoFila {
  void *dados;
  struct NoFila *prox;
} NoFila;

typedef struct Fila {
  NoFila *inicio, *fim;
  int tamanho_dados;
} Fila;

int vazia(Fila* f);

#endif
