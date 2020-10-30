// Diferente do malloc o calloc inicia os valores com zero
// é díficil perceber por ser um comportamento indefinido

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *x = NULL;
  int *y = NULL;

  x = (int *)calloc(1, sizeof(int));
  y = (int *) malloc(sizeof(int));


  /* *y = 10; */

  printf("Calloc: %d. Malloc: %d", *x, *y);
  free(x);
  free(y);
}
