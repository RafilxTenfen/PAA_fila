#include <stdio.h>
#include "fila_pilha/Fila_pilha_interface.h"
#include "fila/Fila_interface.h"

int main(int argc, char** argv) {

  fFila pFila = criar(sizeof(int));

  int enf1 = 4;
  int result = enfileirar(pFila, &enf1);
  printf("\nenfileirar result: %d -> %d", result, enf1);

  int enf2 = 8;
  int result2 = enfileirar(pFila, &enf2);
  printf("\nenfileirar result2: %d -> %d", result2, enf2);

  int enf3 = 15;
  int result3 = enfileirar(pFila, &enf3);
  printf("\nenfileirar result3: %d -> %d", result3, enf3);

  int* desenf1 = desenfileira(pFila);
  printf("\ndesenfileirar -> %d", *desenf1);

  int* desenf2 = desenfileira(pFila);
  printf("\ndesenfileirar -> %d", *desenf2);

  int* desenf3 = desenfileira(pFila);
  printf("\ndesenfileirar -> %d", *desenf3);

  int* desenf4 = desenfileira(pFila);
  if (desenf4 == NULL) {
    printf("\ndesenfileirar IS NULL");
  }


}