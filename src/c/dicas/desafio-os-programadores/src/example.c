#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  char *pedro = "pedro";
  char *expedito = "expedito";

  char *nome_completo = (char *)malloc(strlen(pedro) + strlen(expedito)) + 1;

  strcat(nome_completo, pedro);

  strcat(nome_completo, " ");
  strcat(nome_completo, expedito);

  puts(nome_completo);
  return 0;
}


