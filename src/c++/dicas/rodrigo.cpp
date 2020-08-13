#include <iostream>

using namespace std;

int main() {

  int entradas;

  cin >> entradas;

  int vetor[entradas];

  for (int i = 0; i < entradas; i++) {

    cin >> vetor[i];
  }

  int valor = 0;

  for (int i = 0; i < entradas - 2; i++) {

    if (vetor[i] == 1 and vetor[i + 1] == 0 and vetor[i + 2] == 0) {

      valor++;
    }
  }

  cout << valor << endl;

  return 0;
}
