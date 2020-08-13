#include <stdio.h>
int recu(int n) {
  for (int i = n -1 ; i > 0; i--) {
    n = n + i;
  }
  return n;
}
int recu2(int n) { return ((n + 1) * n) / 2; }
void teste(int x) {
  for (int i = 0; i <= x; i++) {
    printf("Valor de i %d recu %d \nValor de i %d RECU2 %d\n", i, recu(i), i,
           recu2(i));
  }
}
int main(void) {
  teste(10);
  return 0;
}
