#include <iostream>

// C++ suporta tranquilamente programação procedural.
// C++ suporta programação funcional muito bem
// C++ NÂO POSSUI RECURADOR DE MEMORIA || GARBAGE COLLECTOR, por padrão

// struct o acesso sempre é publico
// classe o acesso por padrão sempre é privado
//
// O contrutor é o nome da classe podendo haver varios fazendo uma sobrecarga de
// contrutor e o destrutor é a negação do contrutor com o simbolo ~
//
using namespace std;

int main(void) {
  int *p = new int[10];

  *p = 1;
  *(p+1) = 2;
  cout << *(p +1) << endl;

  delete[] p;
  return 0;
}
