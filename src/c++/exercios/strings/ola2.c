#include <stdio.h>
int main() {
  int i, j, c;
  float soma = 0;
  i = 1;
  j = 15;
  for (c = 1; c <= 15; c++) {
    soma = soma + i / (j * j);
    i *= 2;
    j--;
  }
  printf("%f", soma);
};
