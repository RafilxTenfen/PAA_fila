#include <stdio.h>
#include "fila_pilha/Fila_pilha_interface.h"
#include "fila/Fila_interface.h"

int main(int argc, char** argv) {

  fFila pFila = criar(sizeof(int));

  int enf1 = 4;
  int result = enfileirar(pFila, &enf1);
  printf("\nenfileirar result: %d -> %d", result, enf1);

}