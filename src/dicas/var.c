#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *removeChar(char *str) {
  char *copy;
  copy = malloc((int)strlen(str));
  int i = 1;
  while(str[i] != '\0') {
    copy[i-1] = str[i];
    i++;
  }
  return copy;
}
int main(void) {
  char vet[6] = "jovis";
  puts(vet);
  char *vetCopy = removeChar(vet);
  puts(vetCopy);
  return 0;
}
