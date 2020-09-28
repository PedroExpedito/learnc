// Constantes 
#include<iostream> 

using namespace std;

int main(int argc, char * argv[]){
  const int vet[] = {1, 2, 3};
  const int* p1 = &vet[0];
  int const* p2 = &vet[1];
  const char* const p4 = "Mundo";
  
  cout << "*p1 = " << *p1 << endl;
  cout << "*p2 = " << *p2 << endl;
  cout << "*p4 = " << *p4 << endl;
  

  return 0;
}
