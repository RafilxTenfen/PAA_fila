#ifndef _fila_pilha_privado
#define _fila_pilha_privado

#include "../fila/Fila_interface.h"

typedef struct Fila_Pilha{
    int quantidade_dado_pilha; // tamanho máximo a ser armazenado por pilha
    int tamanho_dado_pilha; // tamanho do dado a ser armazenado na pilha
    fFila fila;
} Fila_Pilha;

#endif
