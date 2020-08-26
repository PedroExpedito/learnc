#include <stdio.h>

int main(void) {
  FILE *file;
  file = fopen("\%appdata\%\\arquivo.txt", "a");

  while(1) {
  fprintf(file, "%s", "Uma frase grande \n\n");
  }
}
