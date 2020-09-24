#include <iostream>

// Em C++ oque fazer quando preciso aumentar o tamanho de um vetor ?
// exemplo eu tenho um ponteiro para inteiro assim
//
// int *vector;
//
// e aloco memoria usando:
//
// vector = new int[6]
//
// porém eu quero alocar mais 4 espalos memoria e se fazer:
//
// vector = new int[10];
//
// os valores das posições anteriores vai ser perdido
//
// eu pensei em fazer um vetor temporário para salvar os dados algo mais o menos assim
// porém tenho quase certeza que eu fiz errado mesmo funcionando

using namespace std;

void changeVectorSize(int *vector, int oldSize, int newSize) {
  int *memory;
  memory = new int[oldSize];
  for ( int i = 0; i < oldSize; i++) {
    memory[i] = vector[i];
  }

  delete[] vector;

  vector = new int[newSize];

  for ( int i = 0; i < oldSize; i++) {
    vector[i] = memory[i];
  }
  delete[] memory;
}

int main(){
  int *vector;
  vector = new int[3];

  // populando array
  for ( int i = 0; i < 3; i++) {
    vector[i] = i;
  }

  // Mudando tamanho do vetor
  changeVectorSize(vector,3,6);
  for ( int i = 2; i < 6; i++) {
    vector[i] = i;
  }

  // imprimindo array
  for ( int i = 0; i < 6; i++) {
  cout << vector[i] << endl;
  }

  delete[] vector;

  return 0;
}
