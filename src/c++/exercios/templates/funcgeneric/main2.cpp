//Sobre templante
//pode criar funções e classes genericas

//tad generica
// FILA primeiro a entrar primeiro a sair FIFO (first in first out)
//
#include <iostream>
#include <list>

using namespace std;

template<class T>

class Queue {
  private:
    list<T> queue;
  public:
    void insert(const T& e){
    }
    bool empty() {
      return queue.empty();
    }
    T remove() {
      if(!this->empty()) {
        T e = queue.front();
        queue.pop_front();
        return e;
      }
      throw "Fila Vazia!!";
    }
};
using namespace std;

int main(void) {
};
