#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#include "Fila_interface.h"
#include "Fila_privado.h"

Fila *criar(int tamanho_dados) {
  Fila *f = (Fila *) malloc(sizeof(Fila));
  if (f == NULL) {
    return NULL;
  }

  f->tamanho_dados = tamanho_dados;
  f->inicio = NULL;
  f->fim = NULL;

  return f;
};

int insere(Fila *f, void *elemento) {
  extern char _etext;
  if (f == NULL || elemento == NULL || !elemento || (char*) elemento < &_etext) {
    return FALSE;
  }

  NoFila *no = (NoFila *) malloc(sizeof(Fila));
  if (no == NULL) {
    return FALSE;
  }

  no->dados = malloc(f->tamanho_dados);
  if (no->dados == NULL) {
    return FALSE;
  }

  no->prox = NULL;
  memcpy(no->dados, elemento, f->tamanho_dados);

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

int destroi(Fila *f) {
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
  return TRUE;
};

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