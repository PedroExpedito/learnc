//Sobre templante
//pode criar funções e classes genericas
//criando funções genericas
//
//exemplo uma função de soma que soma varios tipo de dados como int, float, double
#include <iostream>

using namespace std;

template<typename T> T sum(T n1, T n2) {
  return n1 + n2;
}
int main(void) {
  cout << sum(1,2) <<endl;
  cout << sum(1.43,1.0) <<endl;
};
