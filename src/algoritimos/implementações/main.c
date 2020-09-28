#include <stdio.h>
#include "algorithm.h"

int main(void) {
  int vector[5] = { 5, 2, 4, 1, 5 };
  mergeSort(vector, 0, 5);
  printv(5, vector);
  return 0;
}

