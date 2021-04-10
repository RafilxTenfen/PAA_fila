#include <stdio.h>
#include "fila_pilha/Fila_pilha_interface.h"
// #include "fila/Fila_interface.h"

#define SIZE_PILHA 3

int main(int argc, char** argv) {
  p_fila_pilha pfp = criaFilaPilha(3, sizeof(int));

  int enfPilha1 = 100;
  int resultpf1 = insereFilaPilha(pfp, &enfPilha1);
  printf("\ninsere Fila Pilha result: %d -> %d", resultpf1, enfPilha1);

  int enfPilha2 = 80;
  int resultpf2 = insereFilaPilha(pfp, &enfPilha2);
  printf("\ninsere Fila Pilha result: %d -> %d", resultpf2, enfPilha2);

  int enfPilha3 = 2;
  int resultpf3 = insereFilaPilha(pfp, &enfPilha3);
  printf("\ninsere Fila Pilha result: %d -> %d", resultpf3, enfPilha3);

  int enfPilha4 = 4;
  int resultpf4 = insereFilaPilha(pfp, &enfPilha4);
  printf("\ninsere Fila Pilha result: %d -> %d", resultpf4, enfPilha4);

  int enfPilha5 = 10;
  int resultpf5 = insereFilaPilha(pfp, &enfPilha5);
  printf("\ninsere Fila Pilha result: %d -> %d", resultpf5, enfPilha5);

  int enfPilha6 = 3;
  int resultpf6 = insereFilaPilha(pfp, &enfPilha6);
  printf("\ninsere Fila Pilha result: %d -> %d", resultpf6, enfPilha6);

  int* remove1 = removeFilaPilha(pfp);
  if (remove1 == NULL) {
    printf("remove1 is null");
    return 0;
  }
  printf("\n\ndado removido da pilha fila -> %d", *remove1);

  int* remove2 = removeFilaPilha(pfp);
  printf("\ndado removido da pilha fila -> %d", *remove2);

  int* remove3 = removeFilaPilha(pfp);
  printf("\ndado removido da pilha fila -> %d", *remove3);

  int* remove4 = removeFilaPilha(pfp);
  printf("\ndado removido da pilha fila -> %d", *remove4);

  int* remove5 = removeFilaPilha(pfp);
  printf("\ndado removido da pilha fila -> %d", *remove5);

  int* remove6 = removeFilaPilha(pfp);
  printf("\ndado removido da pilha fila -> %d", *remove6);

  int* remove7 = removeFilaPilha(pfp);
  if (remove7 == NULL) {
    printf("\nremove7 is null");
  } else {
    printf("\ndado removido da pilha fila -> %d", *remove7);
  }

  int destroiResult = destroiFilaPilha(pfp);
  printf("\nDestroi fila e pilha result -> %d", destroiResult);

  // int* topo1 = topoFilaPilha(pfp);
  // printf("\ntopo da pilha fila -> %d", *topo1);

  // fFila pFila = criarFila(sizeof(int));

  // int enf1 = 4;
  // int result = enfileirar(pFila, &enf1);
  // printf("\nenfileirar result: %d -> %d", result, enf1);

  // int enf2 = 8;
  // int result2 = enfileirar(pFila, &enf2);
  // printf("\nenfileirar result2: %d -> %d", result2, enf2);

  // int enf3 = 15;
  // int result3 = enfileirar(pFila, &enf3);
  // printf("\nenfileirar result3: %d -> %d", result3, enf3);

  // int* desenf1 = desenfileira(pFila);
  // printf("\ndesenfileirar -> %d", *desenf1);

  // int* desenf2 = desenfileira(pFila);
  // printf("\ndesenfileirar -> %d", *desenf2);

  // int* desenf3 = desenfileira(pFila);
  // printf("\ndesenfileirar -> %d", *desenf3);

  // int* desenf4 = desenfileira(pFila);
  // if (desenf4 == NULL) {
  //   printf("\ndesenfileirar IS NULL");
  // }


}