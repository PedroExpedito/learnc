#include <stdio.h>
void printBits(unsigned int num) {

  // tamanho
  unsigned int size = sizeof(unsigned int);

  // Potencia maxima fazendo o shift a esquerda
  unsigned int maxPow = 1 << (size * 8 - 1);


  for (int i = 0; i < size * 8; ++i) {

    // printf faz a comparação AND entre o valor do maxPow e do num
    printf("%u ", !!(num&maxPow));
    // faz um shift a esquerda
    num = num << 1;
  }
}

int main(void) {
  int x = 10;
  printBits(x);
}
