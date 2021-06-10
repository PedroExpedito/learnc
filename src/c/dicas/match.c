#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct pessoa {
  char nome[100];
  int age;
} Pessoa;

void printPointer(char *name, void *p) {
  printf("ponteiro %s: %p\n", name, p);
}

typedef bool (*predicado)(void*);

// meu predicado
bool idadeMaiorQueVinte(void *x) {
  Pessoa *tmp = x;

  puts(tmp->nome);

  return tmp->age > 20 ? true : false;
}


bool allMatch(void **array, int size, predicado predi){
  if( array == NULL || size <= 0) return false;

  printf("printar pPessoa0 %p\n", array[0]);

  for ( int i = 0; i < size; i++) {
    puts("entrou");
    if(predi(array[i])) {
      return false;
    }allMatch(pPessoas, 3, idadeMaiorQueVinte);
  }


  return true;
}


int main(void) {
  Pessoa pessoas[3];

  strcpy(pessoas[0].nome, "Pedro");
  pessoas[0].age = 19;

  strcpy(pessoas[1].nome, "Marcos");
  pessoas[1].age = 13;

  strcpy(pessoas[2].nome, "Antonio");
  pessoas[2].age = 18;


  void *pPessoas[3];

  pPessoas[0] = &pessoas[0];
  pPessoas[1] = &pessoas[1];
  pPessoas[2] = &pessoas[2];

  printf("printar pessoa0 %p\n", &pessoas[0]);
  printf("printar pPessoa0 %p\n", pPessoas[0]);

  bool result = allMatch(pPessoas, 3, idadeMaiorQueVinte);

  printf( result ? "true" : "false");

  return 0;
}
