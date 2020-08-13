// vetor em CPP
#include <iostream>

using namespace std;
int main(int argc, char * argv[]){
  int * parray = new int [10];

  cin >> * (parray);

  cout << * (parray) << endl;
  delete[] parray;
  parray = NULL; // Para zerar o endereço do vetor
  return 0;
}
