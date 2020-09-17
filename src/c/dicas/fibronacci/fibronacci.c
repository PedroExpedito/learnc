#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(void) {
  printf("0, 1 ");
  unsigned long long int x = 1,y = 1 ,r = 0;
  while(1) {
    if ( r > INT_MAX - 10) {
      puts("Numero muito alto");
      exit(0);
    }
    r = x + y;
    x = y;
    y = r;
    printf(",%lld ",r );
    }
  return 0;
}
