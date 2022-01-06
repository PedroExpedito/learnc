// um programa parecido com o cat extremamente simples
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char ch;

  if( argc !=2 ) {
    printf("erro nos argumentos\n");
    exit(1);
  }

  if((fp = fopen(argv[1], "r")) == NULL) {
    printf("Arquivo Não pode ser aberto\n");
    exit(1);
  }

  ch = getc(fp);

  while (ch != EOF) {
    putchar(ch);
    ch = getc(fp);
  }


fclose(fp);

}
