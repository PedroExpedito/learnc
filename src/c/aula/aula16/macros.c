#include <stdlib.h> // é uma macro que inclui um arquivo
#include "f.h"
#define MSG "Mensagem padrao"
#define DEBUG


int main(void){
  imprime("ola");
  int num = 100;
#ifdef DEBUG
#define VAR(x) printf("A variavel "#x" tem valor: %d\n", x);
  VAR(num);
  printf("Cheguei");
#endif
}

