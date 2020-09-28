// Qual a diferença entre vector e classe ?
//
// O vector pre aloca memoria para o futuro, cada elemento só possui espaço
// para o tipo dele, já na lista requer espaço extra
//
// Acesso a um elemento de um vetor é muito rápido, porém remover um elemento
// é muito lento, recomendado para dados que mudarão pouco ao longo do tempo
//
// Para muita inserção e remoção usar lista
//
// Já para acesso rápido usar vector
//
// lista duplamente encadeada
//
#include <iostream>
#include <list>

using namespace std;

int main(void) {
  list<int> l1;
  list<int> l2(3,10);
  list<int>::iterator it;

  l1.push_back(10); // l1 tem 10;

  l1.push_front(5);

  cout << "Mostrando os elementos de l1:\n" << endl;

  for ( it = l1.begin(); it != l1.end(); it++)
    cout << *it << endl;

  cout << "Mostrando os elementos de l2:\n" << endl;

  for ( it = l2.begin(); it != l2.end(); it++)
    cout << *it << endl;
  l1.clear();

  cout << "Vazio: "<<  l1.empty() << endl;
  return 0;
}
