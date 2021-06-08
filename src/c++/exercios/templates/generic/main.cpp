//Sobre templante
//pode criar funções e classes genericas
//criando funções genericas
//
//exemplo uma função de soma que soma varios tipo de dados como int, float, double
#include <stdio.h>

// char
// por que

int soma(char n1, char n2) {
 return  n1 + n2;
}

int main(void) {
  printf("como numero: %d",soma('p', 'o'));
  return 0;
};
