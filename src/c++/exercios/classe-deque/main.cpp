// baterias inclusas
// classe deque
//
// Fila de duas pontas
// a diferença da fila (FIFO) é que o deque pode aumentar e diminuir
// em ambas as pontas
#include <deque>
#include <iostream>

using namespace std;

int main() {
  deque<int> fila;

  // inserir no final
  fila.push_back(20);
  fila.push_back(30);
  // inserir na frente
  fila.push_front(10);

  deque<int>::iterator it = fila.begin();

  while(it !=  fila.end()) {
    cout << *it++ << " ";
  }
  return 0;
}
