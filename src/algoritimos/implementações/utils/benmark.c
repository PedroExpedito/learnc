#include <stdio.h>
#include <stdlib.h>
#include "algorithm.h"

#define MAX 9000

int populateArrayInt(int size, int *array) {
  for ( long long int i = 0; i < size; i++) {
    array[i] = rand();
  }
  return 0;
}
int printIntArray(int size, int *array) {
  for ( long long int i = 0; i < size; i++) {
    printf("%d\n", array[i]);
  }
  return 0;
}

int main(void) {
  int array[MAX];
  populateArrayInt(MAX,array);
  bubbleSort(MAX,array);
  printIntArray(MAX, array);
  return 0;
}

