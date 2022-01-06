#include <stdio.h>

int main(int argc, char **argv) {

  if(argc < 1) { return 1; }

  FILE *file = fopen(argv[1], "rb");

  if(file == NULL) {
    return 1;
  }

  int c = getc(file);

  while(c != EOF) {
    putchar(c);
    c = getc(file);
  }

  return 0;
}
