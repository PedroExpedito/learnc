#include <stdio.h>

int main(void) {
  FILE *file;
  file = fopen("arquivo.txt", "r");
  fclose(file);

  return 0;
}
