#include <stdio.h>
#include <stdlib.h>

#include "../fila/Fila_interface.h"
#include "../pilha/Pilha_interface.h"
#include "Fila_pilha_interface.h"
#include "Fila_pilha_privado.h"

#define TRUE 1
#define FALSE 0

p_fila_pilha criaFilaPilha(int quantidade_dado_pilha, int tamanho_dado_pilha) {
  p_fila_pilha pfp = malloc(sizeof(Fila_Pilha));
  if (pfp == NULL || quantidade_dado_pilha <= 0 || tamanho_dado_pilha <= 0) {
    return NULL;
  }

  printf("\ncriaFilaPilha qnt: %d tamanhoInfo: %d", quantidade_dado_pilha, tamanho_dado_pilha);
  pPilha pPilhaV = criaPilha(quantidade_dado_pilha, tamanho_dado_pilha);
  if (pPilhaV == NULL) {
    return NULL;
  }

  // printPilha(pPilhaV);
  // NOTE VALOR DE TAMANHO DADOS NA PILHA

  fFila pFila = criarFila(sizeof(pPilha));
  if (pFila == NULL) {
    return NULL;
  }

  if (enfileirar(pFila, pPilhaV) == FALSE) {
    return NULL;
  }

  // printFila(pFila);
  // printf("\nsize of pilha: %ld", sizeof pPilhaV);
  // pPilha inicioFilaPilhaValue = inicioFila(pFila);
  // printPilha(inicioFilaPilhaValue);
  // NOTE VALOR DE TAMANHO DADOS NA PILHA DNV

  pfp->fila = pFila;
  pfp->quantidade_dado_pilha = quantidade_dado_pilha;
  pfp->tamanho_dado_pilha = tamanho_dado_pilha;

  return pfp;
}

int insereNovaPilha(p_fila_pilha pfp, void* elemento) {
  printf("\ninsereNovaPilhaINIT");
  pPilha pPilha = criaPilha(pfp->quantidade_dado_pilha, pfp->tamanho_dado_pilha);
  if (pPilha == NULL) {
    return FALSE;
  }
  // printPilha(pPilha);
  if (empilha(pPilha, elemento) == FALSE) {  // algo de errado aconteceu ao empilhar
    printf("insereNovaPilha empilha deu false");
    return FALSE;
  }
  // printPilha(pPilha);
  return enfileirar(pfp->fila, pPilha);
}

int insereFilaPilha(p_fila_pilha pfp, void* elemento) {
  // printf("\n\ninsereFilaPilha");
  if (pfp == NULL || pfp->fila == NULL) {
    return FALSE;
  }

  pPilha fimFilaPilha = fimFila(pfp->fila);
  if (fimFilaPilha == NULL) {
    printf("\nfim da fila is null, nao deve cair aqui");  // mas se cair, insere novo rsrs
    return insereNovaPilha(pfp, elemento);
  }

  // printf("\n");
  // printf("\np_fila_pilha %p \nfila %p  \npilha %p", pfp, pfp->fila, fimFilaPilha);
  // printf("\n");
  // printPilha(fimFilaPilha);
  // printf("\n");

  if (empilha(fimFilaPilha, elemento) == TRUE) {  // se conseguiu empilhar
    printf("\nconseguiu empilhar");
    return TRUE;
  }

  printf("\npilha esta cheia, deve enfileirar uma nova");
  // pilha esta cheia
  return insereNovaPilha(pfp, elemento);
}

void* removeFilaPilha(p_fila_pilha pfp) {
  if (pfp == NULL || pfp->fila == NULL) {
    return NULL;
  }

  // pPilha inicioFilaPilha = desenfileira(pfp->fila);
  pPilha inicioFilaPilha = inicioFila(pfp->fila);
  if (inicioFilaPilha == NULL) {  // nao tem fila
    printf("\nremoveFilaPilha nao tem mais dados na fila");
    return NULL;
  }

  // tem pilha
  void* dados = desempilha(inicioFilaPilha);
  if (dados != NULL) {  // retorna os dados que desempilhou
    return dados;
  }

  // não tem mais dados na pilha, pode desinfileirar
  printf("\nremoveFilaPilha nao tem mais dados na PILHA, deve desenfileirar");
  if (desenfileira(pfp->fila) == NULL) {
    return NULL;
  }
  return removeFilaPilha(pfp);
}

void* topoFilaPilha(p_fila_pilha pfp) {
  if (pfp == NULL || pfp->fila == NULL) {
    return NULL;
  }

  pPilha inicioFilaPilha = inicioFila(pfp->fila);
  if (inicioFilaPilha == NULL) {
    printf("inicio da fila is null");
    return NULL;
  }
  // printf("\n topoFilaPilha INIT");
  // printPilha(inicioFilaPilha);
  return topoPilha(inicioFilaPilha);
}

int destroiFilaPilha(p_fila_pilha pfp) {
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