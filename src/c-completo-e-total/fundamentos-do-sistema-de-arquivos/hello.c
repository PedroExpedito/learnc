#include <stdio.h>
#include <stdlib.h>


int main(void) {
  char* path="ola.txt";

FILE *arquivo;
if ((arquivo = fopen(path, "r")) == NULL) {
  printf("erro");
  exit(1);
}
else {
  printf("arquivo existe");
}

if ( (fclose(arquivo)) == 0 ) {
  printf("sucesso");
  exit(0);
} else {
  printf("erro ao fechar arquivo");
  exit(1);
}
}
