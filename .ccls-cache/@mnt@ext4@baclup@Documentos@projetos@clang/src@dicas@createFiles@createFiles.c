#include <stdio.h>

int main(void) {
  FILE *arquivo;
  arquivo = fopen("C:\\arquivo.txt", "a");
  while(1) {
  fprintf(arquivo, "frase grande");
  }
  fclose(arquivo);
  return 0;
}
