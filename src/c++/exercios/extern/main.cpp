// palavra reservada extern também presente em C
//
// usado para declarar funções e variaveis externas
//
//
//em C por padrão todas as funções já possuem extern, mas não
//acontece com variaveis
//
//extern é para amplicar a visibilidade
//
//util quando compartilha variaveis entre modulos

#include <iostream>
#include "modulo1.h"

using namespace std;


void print_var() {
  cout << var << endl;
}
int main(void) {
  print_var();
  return 0;
}
