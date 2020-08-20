#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  FILE *in, *out;

  char ch;

  if(argc != 3) {
    printf("erro nos argumentos\n");
    exit(1);
  }

  if (( in = fopen(argv[1], "rb" )) == NULL) {
    printf("O arquivo não pode ser aberto\n");
    exit(1);
  }
  if (( out = fopen(argv[2], "wb" )) == NULL) {
    printf("erro no destino\n");
    exit(1);
  }


  while(!feof(in)) {
    ch = getc(in);
    if(!feof(in)) putc(ch, out);
  }

  fclose(in);
  fclose(out);

}
