// namespace servem para evitar colisão de nomes
// podendo duas bibliotecas terem metodo com o mesmo nome
// e fazer a diferenciação pelo contexto

#include <iostream>


namespace ns1 {
  int num = 42;
}
namespace ns2 {
  int num = 52;
}

// using namespace ns1;
// using namespace ns2;

int main(void) {
  std::cout << ns1::num << '\n';
  return 0;
}
