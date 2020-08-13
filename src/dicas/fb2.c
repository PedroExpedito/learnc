#include <stdio.h>
#include <stdlib.h>


// definindo estruturas
typedef struct lista {
  int qnt;
  struct registro *inicio;
} lista;

typedef struct registro {
  int valor;
  struct registro *prox;
} registro;

// Prototipação
lista *aloca_lista();
registro *aloca_registro();
void incluir(lista *l, int x);
void soma(lista *l);

// int main
int main() {
  lista *l;
  l = aloca_lista();
  soma(l);

  return 0;
}

// funções
lista *aloca_lista() {
  lista *novo;
  novo = (lista *)malloc(sizeof(lista));
  novo->inicio = NULL;
  novo->qnt = 0;
  return novo;
}

registro *aloca_registro() {
  registro *novo;
  novo = (registro *)malloc(sizeof(registro));
  novo->valor = 0;
  novo->prox = NULL;
  return novo;
}

void incluir(lista *l, int tempo) {
  registro *novo, *aux;
  int i, pessoas;
  novo = aloca_registro();
  novo->valor = tempo;

  printf("Digite o numero de pessoas na fila \n");
  scanf("%d", &pessoas);

  for (i = 0; i < pessoas; i++) {

    printf("Digite o tempo da pessoa na fila: \n");
    scanf("%d", &tempo);

    if (l->qnt == 0) {
      l->inicio = novo;
    } else {
      aux = l->inicio;

      while (aux->prox != NULL) {
        aux = aux->prox;
      }
      aux->prox = novo;
    }
    l->qnt++;
  }
}

void soma(lista *l) {
  registro *aux, *add;
  aux = l->inicio;
  add = aux;

  if (aux == NULL) {
    printf("Nenhum fumante na fila \n");
  } else {

    while (aux != NULL) {
      add = add + aux->valor;
      aux = aux->prox;
    }
    printf("Felipe vai demorar %d segundos", add->valor);
  }
}
