// para ler executavel de windows
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib/petest.h"

void fatal(char *msg) {
  if (msg != NULL)
    fprintf(stderr, "Erro: %s\n", msg);
  exit(1);
}

void usage(char *msg) {
  printf("Uso:\n\treadpe <arquixo.exe>\n");
  fatal(NULL);
}

int main(int argc, char *argv[]) {
  FILE *fh;
  unsigned char buffer[32];

  if (argc != 2)
    usage("faltando nome do arquivo");

  printf("%s\n", argv[1]);

  fh = fopen(argv[1], "rb");

  if (fh == NULL)
    fatal("arquivo não encontrado ou sem permissão de leitura");
  if (fread(buffer, 32, 1, fh) != 1) {
    fatal("ERRO");
  }
  fclose(fh);
  if (!pe_ispe(buffer))
    printf("Não é um PE");
  return 0;
}
