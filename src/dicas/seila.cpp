#include <iostream>

using namespace std;

int main(void){
  string C = "Expedito";
  char A[] = "pedro";
  char B[] = "lapis";
  int i=0;
  while(A[i] !='\0') {// Repete o while até encontrar em pA o fim de string
         B[i] = A[i];
         i++;
  }
  B[i+1] = '\0';


cout << B << C << endl;


  return 0;
}
