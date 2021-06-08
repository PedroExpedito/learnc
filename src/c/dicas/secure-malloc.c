#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *s_malloc(size_t size) {
  void *tmp = malloc(size);
  if ( tmp == NULL ) {
    fprintf(stderr, "memory error\n");
    exit(1);
  }
  return tmp;
}

int main() {
  char *nome;
  nome = s_malloc(999999);

  strcpy(nome,"pedro");
  printf("nome: %s\n", nome);

  return 0;

}

