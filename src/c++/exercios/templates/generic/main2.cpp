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
      queue.push_back(e);
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
      throw "Fila Vazia!!!";
    }
    T front() {
      if(!this->empty()) {
        return queue.front();
      }
      throw "Fila Vazia!!!";
    }
    T back() {
      if(!this->empty()) {
        return queue.back();
      }
      throw "Fila Vazia!!!";
    }

    int size() {
      return queue.size();
    }

};
using namespace std;

int main(void) {
  Queue<double> f1;
  Queue<string> f2;

  f2.insert("Pedro");

  try {
  cout << f2.front() << endl;
  } catch( const char *error) {
    cout << error << endl;
  }

  cout << "Antes de inserir elementos..\n";

  if(f1.empty()) {
    cout << "Fila vazia\n";
  } else {
    cout << "Não vazia";
  }

  cout << "Remover da fila\n";

  try {
    double e = f1.remove();
    cout << "Removido:" << e;
  } catch(const char * msg) {
    cerr << "Error: " << msg << endl;
  }

  f1.insert(12.43);
  f1.insert(13.43);
  f1.insert(14.43);

  cout << "Depois de remover\n";

  try {
    double e = f1.remove();
    cout << "Removido:" << e << endl;
  } catch(const char * msg) {
    cerr << "Error: " << msg << endl;
  }

  try {
  cout << "Elemento frente: " << f1.front() << endl;
  } catch(const char *error) {
    cout << error << endl;
  }

  try {
  cout << "Elemento final: " << f1.back() << endl;
  } catch(const char *error) {
    cout << error << endl;
  }
};
