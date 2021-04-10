#include <stdio.h>
#include <stdlib.h>

#include "pilha/Pilha_interface.h"

struct teste {
  int i;
  double d;
};

int main(int argc, char* argv[]) {
  pPilha p = criaPilha(3, sizeof(int));
  if (p) {
    printf("deu tudo certo\n");
    int* a = malloc(sizeof(int));
    int* b = malloc(sizeof(int));
    *b = 0;

    *a = 1;
    empilha(p, a);

    *a = 2;
    empilha(p, a);

    *a = 3;
    empilha(p, a);

    b = desempilha(p);
    printf("%d\n", *b);

    *a = 4;
    empilha(p, a);

    b = desempilha(p);
    printf("%d\n", *b);

    b = desempilha(p);
    printf("%d\n", *b);

    b = desempilha(p);
    printf("%d\n", *b);

    b = desempilha(p);
    printf("Retorna nulo %d\n", b);

    *a = 5;
    empilha(p, a);

    b = malloc(sizeof(int));
    b = desempilha(p);
    printf("%d\n", *b);

    b = desempilha(p);
    printf("Retorna nulo %d\n", b);

  } else {
    printf("Erro ao criar pilha\n");
  }
  return 0;
}