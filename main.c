#include <stdio.h>
#include "main.h"
#include "fila_pilha/Fila_pilha_interface.h"

void ins_int( p_fila_pilha pfp, int value ){
    int enfPilha1 = value;
    int resultpf1 = insere(pfp, &enfPilha1);
    if (resultpf1) {
      printf("insere Fila Pilha result: %d -> %d\n", resultpf1, enfPilha1);
    }
}

void ins_char( p_fila_pilha pfp, char value ){
    int enfPilha1 = value;
    int resultpf1 = insere(pfp, &enfPilha1);
    if (resultpf1) {
      printf("insere Fila Pilha result: %d -> %c\n", resultpf1, enfPilha1);
    }
}

void ins_double( p_fila_pilha pfp, double value ){
    double enfPilha1 = value;
    int resultpf1 = insere(pfp, &enfPilha1);
    if (resultpf1) {
      printf("insere Fila Pilha result: %d -> %.1f\n", resultpf1, enfPilha1);
    }
}

void ret_int( p_fila_pilha pfp ){
    int* remove = retira(pfp);
    if (remove == NULL) {
      printf("remove is null\n");
      return ;
    }
    printf("dado removido da pilha fila -> %d\n", *remove);
}

void ret_char( p_fila_pilha pfp ){
    char* remove = retira(pfp);
    if (remove == NULL) {
      printf("remove is null\n");
      return ;
    }
    printf("dado removido da pilha fila -> %c\n", *remove);
}

void ret_double( p_fila_pilha pfp ){
    double* remove = retira(pfp);
    if (remove == NULL) {
      printf("remove is null\n");
      return ;
    }
    printf("dado removido da pilha fila -> %.1f\n", *remove);
}

void teste_int(){
  p_fila_pilha pfp = criar(SIZE_PILHA, sizeof(int));

  ins_int( pfp, 100 );
  ins_int( pfp, 80 );
  ins_int( pfp, 2 );
  ins_int( pfp, 4 );
  ins_int( pfp, 10 );
  ins_int( pfp, 3 );
  ins_int( pfp, 99 );
  ins_int( pfp, 84 );
  ins_int( pfp, 222 );

  ret_int( pfp );
  ret_int( pfp );
  ret_int( pfp );
  ret_int( pfp );
  ret_int( pfp );
  ret_int( pfp );
  ret_int( pfp );
  ret_int( pfp );
  ret_int( pfp );

  // Outro testes
  ret_int( pfp );
  ins_int( pfp, 1 );
  ins_int( pfp, 2);
  ins_int( pfp, 3);
  ins_int( pfp, 4);

  ret_int( pfp );
  ret_int( pfp );
  ret_int( pfp );
  ret_int( pfp );
  ret_int( pfp );
  ret_int( pfp );

  ins_int( pfp, 1 );
  ins_int( pfp, 2 );
  ret_int( pfp );
  ins_int( pfp, 3 );
  ret_int( pfp );
  ins_int( pfp, 4 );
  ret_int( pfp );

  int destroiResult = destruir(pfp);
  printf("Destroi fila e pilha result -> %d\n", destroiResult);
}

void teste_char(){
  p_fila_pilha pfp = criar(SIZE_PILHA, sizeof(char));

  ins_char( pfp, 'a' );
  ins_char( pfp, 'b' );
  ins_char( pfp, 'c' );
  
  ret_char( pfp );

  int destroiResult = destruir(pfp);
  printf("Destroi fila e pilha result -> %d\n", destroiResult);
}

void teste_double(){
  p_fila_pilha pfp = criar(SIZE_PILHA, sizeof(double));

  ins_double( pfp, 1.0 );
  ins_double( pfp, 2.0 );
  ins_double( pfp, 3.0 );
  
  ret_double( pfp );
  int destroiResult = destruir(pfp);
  printf("Destroi fila e pilha result -> %d\n", destroiResult);
}

int main(int argc, char** argv) {
  teste_int();

  return 0;
}