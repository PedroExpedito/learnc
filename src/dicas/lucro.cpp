#include <iostream> // para incluir ao seu codigo uma biblioca de entrada e saida que alguém muito legal escreveu...

using namespace std; // meio que as função que você chamar faz parte da coleção std... pesquisa no google

int main(void) {

  float compra,venda;
  cout << "Informe o valor de compra: " <<endl;
  cin >> compra;
  cout << "Informe o valor de venda: " <<endl;
  cin >> venda;

  cout << "Seu lucro foi de: "<< venda - compra << endl;

}

