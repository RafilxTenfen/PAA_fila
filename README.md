# Fila dinâmica de Pilhas estáticas

- Conforme exemplificado na imagem abaixo:
- ![](https://i.imgur.com/0CykNkr.png)

### Dependencias
- [linux](https://www.linux.org/pages/download/)
- [GCC](https://gcc.gnu.org/install/index.html)
- [make](https://www.unixmen.com/install-ubuntu-make-on-ubuntu-15-04/)

### Métodos Publicos

```c
// PAA_fila/fila_pilha/Fila_pilha_interface.h

typedef struct Fila_Pilha *p_fila_pilha;

// alloca memoria para criar a fila de pilhas
// quantidade_dado_pilha -> quantidade de dados no vetor da pilha
// tamanho_dado_pilha -> tamanho de dados a ser alocado ex.: sizeof(int)
p_fila_pilha criaFilaPilha(int quantidade_dado_pilha, int tamanho_dado_pilha);

// libera a memoria ocupada da fila de pilhas
int destroiFilaPilha(p_fila_pilha pp);

// adiciona elemento na fila de pilhas
int insereFilaPilha(p_fila_pilha p, void *elemento);

// remove elemento da fila pilha se for inserido [100, 80, 2] [4, 10, 3]
// e removeFilaPilha foi invocado, deve retornar 2
void* removeFilaPilha(p_fila_pilha p);

// se for inserido [4, 10, 3]
// deve retornar o valor 3
void* topoFilaPilha(p_fila_pilha p);

```

### Como buildar
- Para buildar você deve criar o `main.h` e `main.c` no root do projeto ex.:
```c
// main.h
#define SIZE_PILHA 3
```

```c
// main.c
#include <stdio.h>
#include "main.h"
#include "fila_pilha/Fila_pilha_interface.h"

int main(int argc, char** argv) {
  p_fila_pilha pfp = criaFilaPilha(SIZE_PILHA, sizeof(int));

  int enfPilha1 = 100;
  int resultpf1 = insereFilaPilha(pfp, &enfPilha1);
  if (resultpf1) {
    printf("\ninsere Fila Pilha result: %d -> %d", resultpf1, enfPilha1);
  }

  int enfPilha2 = 80;
  int resultpf2 = insereFilaPilha(pfp, &enfPilha2);
  if (resultpf2) {
    printf("\ninsere Fila Pilha result: %d -> %d", resultpf2, enfPilha2);
  }

  int enfPilha3 = 2;
  int resultpf3 = insereFilaPilha(pfp, &enfPilha3);
  if (resultpf3) {
    printf("\ninsere Fila Pilha result: %d -> %d", resultpf3, enfPilha3);
  }

  int enfPilha4 = 4;
  int resultpf4 = insereFilaPilha(pfp, &enfPilha4);
  if (resultpf4) {
    printf("\ninsere Fila Pilha result: %d -> %d", resultpf4, enfPilha4);
  }

  int* remove1 = removeFilaPilha(pfp);
  if (remove1 == NULL) {
    printf("remove1 is null");
    return 1;
  }
  printf("\n\ndado removido da pilha fila -> %d", *remove1);

  int destroiResult = destroiFilaPilha(pfp);
  printf("\nDestroi fila e pilha result -> %d", destroiResult);

  return 0;
}

```

- Execute o comando `make`
__Resultado Esperado__
![](https://i.imgur.com/8p6Uvs8.png)

- Deve gerar o arquivo executável `main`

### Como Executar
- Após realizar o build do executável com `make`
- Rode o arquivo com a seguinte linha de comando
```shell
./main
```

__Resultado Esperado__
- ![](https://i.imgur.com/2dCbRys.png)

> Para limpar, realizar o build e executar o main use `make run`
