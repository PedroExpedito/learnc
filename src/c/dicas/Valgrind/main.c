#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *str = malloc(sizeof(char) * 10);
  strcpy(str, "Pedro");
  puts(str);
  free(str);
  strcpy(str, "Pedro");
}
