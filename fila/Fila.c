#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#include "Fila_interface.h"
#include "Fila_privado.h"

Fila *criarFila(int tamanho_dados) {
  Fila *f = (Fila *) malloc(sizeof(Fila));
  if (f == NULL) {
    return NULL;
  }

  f->tamanho_dados = tamanho_dados;
  f->inicio = NULL;
  f->fim = NULL;

  return f;
};

int enfileirar(Fila *f, void *elemento) {
  extern char _etext;
  if (f == NULL || elemento == NULL || !elemento || (char*) elemento < &_etext) {
    return FALSE;
  }
  printf("\nEnfileirar size of elem: %ld\ntamanho dados: %d", sizeof(elemento), f->tamanho_dados);

  NoFila* no = malloc(sizeof(struct NoFila));
  if (no == NULL) {
    return FALSE;
  }

  no->dados = malloc(f->tamanho_dados);
  if (no->dados == NULL) {
    return FALSE;
  }

  no->prox = NULL;
  no->dados = elemento;
  // verificar como enfileirar dados na fila
  // void* temp = malloc(f->tamanho_dados);
  // memcpy(no->dados, elemento, f->tamanho_dados);
  // no->dados = temp;

  if (vazia(f) == TRUE) {
    f->inicio = no;
  } else {             // contains something in the slice
    f->fim->prox = no;  // receive next, because the end is the pointer of the previous
  }
  f->fim = no;
  // printFila(f);
  return TRUE;
};

void* desenfileira(Fila *f) {
  if (f == NULL) {
    return NULL;
  }

  if (vazia(f) == TRUE) {
    return NULL;
  }

  void *dados = malloc(f->tamanho_dados);

  NoFila *current = f->inicio;
  memcpy(dados, current->dados, f->tamanho_dados);
  f->inicio = current->prox;

  if (f->inicio == NULL) {
    f->fim = NULL;
  }
  if (current != NULL) {
    if (current->dados != NULL) {
      free(current->dados);
    }
    free(current);
  }

  return dados;
};

int destroiFila(Fila *f) {
  if (f == NULL) {
    return FALSE;
  }

  while (f->inicio != NULL) {
    NoFila* current = f->inicio;
    if (!current->prox->dados) {
      free(current->prox->dados);
    }
    if (!current->prox) {
      free(current->prox);
    }
    f->inicio = f->inicio->prox;
    if (current->dados != NULL) {
      free(current->dados);
    }
    free(current);
  }

  free(f);
  return TRUE;
};

void* fimFila(fFila f) {
  if (vazia(f) == TRUE) {
    return NULL;
  }

  NoFila* current = f->inicio;
  while (current != NULL) {
    if (current->prox == NULL) {
      return current->dados;
    }
    current = current->prox;
  }

  return NULL;
}

void* inicioFila(fFila f) {
  if (vazia(f) == TRUE) {
    return NULL;
  }

  return f->inicio->dados;
}

int vazia(Fila *f) {
  if (f == NULL) {
    return TRUE;
  }
  if (f->inicio == NULL) {
    return TRUE;
  }
  if (f->fim == NULL) {
    return TRUE;
  }
  return FALSE;
}

void printFila(fFila f) {
  printf("\nPRINT_FILA\npointer %p\ntamanho dados: %d", f, f->tamanho_dados);
}
