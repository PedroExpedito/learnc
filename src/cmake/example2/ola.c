#include <stdio.h>

int main(void) {
  unsigned char a = 1;
  a = a~;

  printf("%d", a);
  return 0;
}
