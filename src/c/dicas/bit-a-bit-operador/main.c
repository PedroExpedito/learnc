#include <stdio.h>
// bitwise

int main(void) {
  int a =2; // 10
  char b =3; // 11
  int bin = 0b00000000000000000000000000000000;
  int bin2 = 0b11111111111111111111111111111111;


            // 10 = 2 &
            // 10 = 3 |
            // 01 = 1 ^
            // só da para negar um por vez ~
            // exemplo com o b que é o valor 3 ou seja
            // 11 em binario só que o int é 4 bytes então ele é
            // 000000000 000000000 000000000 000000011 então a
            // sua negação é:
            // 111111111 111111111 111111111 111111100 que por
            // ser signed é igual a -4 em decimal

  if (bin == ~bin2) {
    printf("Sim");
  }

  return 0;
}
