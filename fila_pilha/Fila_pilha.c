#include <stdio.h>
#include <stdlib.h>

#include "../fila/Fila_interface.h"
#include "../pilha/Pilha_interface.h"
#include "Fila_pilha_interface.h"
#include "Fila_pilha_privado.h"

#define TRUE 1
#define FALSE 0

p_fila_pilha criar(int quantidade_dado_pilha, int tamanho_dado_pilha) {
  p_fila_pilha pfp = malloc(sizeof(Fila_Pilha));
  if (pfp == NULL || quantidade_dado_pilha <= 0 || tamanho_dado_pilha <= 0) {
    return NULL;
  }

  pPilha pPilhaV = criaPilha(quantidade_dado_pilha, tamanho_dado_pilha);
  if (pPilhaV == NULL) {
    return NULL;
  }

  fFila pFila = criarFila(sizeof(pPilha));
  if (pFila == NULL) {
    return NULL;
  }

  if (enfileirar(pFila, pPilhaV) == FALSE) {
    return NULL;
  }

  pfp->fila = pFila;
  pfp->quantidade_dado_pilha = quantidade_dado_pilha;
  pfp->tamanho_dado_pilha = tamanho_dado_pilha;

  return pfp;
}

int insereNovaPilha(p_fila_pilha pfp, void* elemento) {
  pPilha pPilha = criaPilha(pfp->quantidade_dado_pilha, pfp->tamanho_dado_pilha);
  if (pPilha == NULL) {
    return FALSE;
  }
  if (empilha(pPilha, elemento) == FALSE) {
    return FALSE;
  }
  return enfileirar(pfp->fila, pPilha);
}

int insere(p_fila_pilha pfp, void* elemento) {
  if (pfp == NULL || pfp->fila == NULL) {
    return FALSE;
  }

  pPilha fimFilaPilha = fimFila(pfp->fila);
  if (fimFilaPilha == NULL) {
    return insereNovaPilha(pfp, elemento);
  }

  if (empilha(fimFilaPilha, elemento) == TRUE) {
    return TRUE;
  }

  return insereNovaPilha(pfp, elemento);
}

void* retira(p_fila_pilha pfp) {
  if (pfp == NULL || pfp->fila == NULL) {
    return NULL;
  }

  pPilha inicioFilaPilha = inicioFila(pfp->fila);
  if (inicioFilaPilha == NULL) {
    return NULL;
  }

  void* dados = desempilha(inicioFilaPilha);
  if (dados != NULL) {
    return dados;
  }

  if (desenfileira(pfp->fila) == NULL) {
    return NULL;
  }
  return retira(pfp);
}

int destruir(p_fila_pilha pfp) {
  if (pfp == NULL) {
    return FALSE;
  }

  pPilha pilhaDesenfileirada = desenfileira(pfp->fila);
  while (pilhaDesenfileirada != NULL) {
    destroiPilha(pilhaDesenfileirada);
    pilhaDesenfileirada = desenfileira(pfp->fila);
  }

  destroiFila(pfp->fila);
  free(pfp);

  return TRUE;
}