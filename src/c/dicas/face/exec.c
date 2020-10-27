#include <stdio.h>
#include <stdlib.h>

int main() {
  int i,n,s=0;


  for( i = 1; i <= 10; i++) {
    s += i;
  }

  printf("A soma dos dez valores é de: %d", s);
  return 0;
}
