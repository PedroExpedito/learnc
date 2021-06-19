#include <stdio.h>

int main(int argc, char **argv) {
  printf("quantos args %d\n", argc);
  int c;
  while ((c = getchar()) != EOF) {
    putchar(c);
  }

  return (0);
}
