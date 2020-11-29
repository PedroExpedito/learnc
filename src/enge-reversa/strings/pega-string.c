#include <stdio.h>
#include <stdlib.h>

int printable(char byte) {
  if (byte >= 0x20 && byte <= 0x7e) {
    return 1;
  }
  return 0;
}

int main( int argc, char *argv[] ) {
  if ( argc < 2 ) {
    fprintf(stderr, "ERROR: no input file\n");
    exit(1);
  }
  FILE *fp = fopen(argv[1], "rb");
  unsigned char byte;

  int find = 0;

  while(fread(&byte, sizeof(byte), 1, fp)) {
    if (printable(byte) && printable(byte+1) && (printable(byte +2) || byte == '\0')) {
      find = 1;
      printf("%c", byte);
    } else if ( find == 1 ) {
      find = 0;
      puts("");
    }
  }
  fclose(fp);

  return 0;
}
