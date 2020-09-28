#include <stdio.h>
#include <stdbool.h>

#define typeof(x) _Generic((x),\
  char: "char",\
  int: "int",\
  float: "float",\
  double: "double",\
  bool: "bool",\
  pessoaIn: "pessoaIn",\
  default: "tipo desconhecido")

typedef struct pessoa
{
  char *nome;
  int idade;
} pessoaIn;

pessoaIn ola;

pessoaIn *Pola = &ola;


int *ponteiro = &ola.idade;


int main(void) {
  double j = 10;
  bool bol = true;
  printf("%s, %s \n", typeof(ola), typeof(bol));
}
