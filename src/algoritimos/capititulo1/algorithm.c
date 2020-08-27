#include <stdio.h>
#include "algorithm.h"

/* imprimir vetores */
int printv(int size, int *value) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d", value[i]);
  }
  printf("\n");
  return i;
}

/* quadrado de numero  */
int quad(int n) {
  printf("%d",n);
  return n*n;
}
/* ordenar vetor em ordem crescente*/
int sort(int size, int *vector) {
  int aux;
  for (int j = 0; j < size; j++) {
    for (int i = 0; i < size; i++) {
      if (vector[i+1] < vector[i]) {
        aux = vector[i+1];
        vector[i+1] = vector[i];
        vector[i] = aux;
      }
    }
  }
  return 0;
}
