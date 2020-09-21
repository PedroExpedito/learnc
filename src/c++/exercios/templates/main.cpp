#include <iostream>
#include "stack.hpp"
#define print(msg) std::cout << msg << std::endl

// Todo elemento é inserido no topo, para desempilhas também é no topo.
// Primeiro a entrar ultimo a sair FILO First In Last Out || Lanst In First Out
//
// Implementando Stack

int main(void) {
  Stack<int> s(10);
  s.push(10);
  s.push(20);
  s.pop();

  std::cout << "Pilha vazia: " << s.empty() << std::endl;
  std::cout << "Top: " << s.getTop() << std::endl;

  s.pop();

  return 0;
}
