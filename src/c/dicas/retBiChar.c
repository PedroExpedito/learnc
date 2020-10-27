#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **ret() {
  char **b;
  b = (char **)malloc(3 * sizeof(char *));
  b[0] = (char *)malloc(strlen("abc") + 1);
  b[1] = (char *)malloc(strlen("Pedro") + 1);
  strcpy(b[0], "abc");
  strcpy(b[1], "Pedro");
  return b;
}

int main(void) {
  char **biChar = ret();;
  printf("%s\n", biChar[1]);
  free(biChar);
}
