#include <stdio.h>

int main(void) {
  int vetor[] = {1,9, 2, 20, 3, 4, 5};
  int i, n = 5;

  for (i = 0; i < n; i++) {
    printf("%d", vetor[i]);
  }
  printf("\n");

  /* ESCRAVA AQUI SEU CODIGO */
  int aux;
  for (int i = 0; i < (n / 2); i++) {
    aux = vetor[i];
    vetor[i] = vetor[n - i - 1];
    vetor[n - i - 1] = aux;
  }

  for (i = 0; i < n; i++) {
    printf("%d", vetor[i]);
  }
  printf("\n");
}
