#include <iostream>

/* variaveis globais bla bla
 * variaveis staticserve para saber quantas vezes uma variavel rodou*/

using namespace std;
int num_global =12;

void foo(){
  static int num_static =1;
  cout << "Vaviavel Local static" << num_static <<endl;

  int num = 10;
  cout << num << endl;
}
int main(int argc, char * argv[]){
  foo();
  cout << num_global << endl;
  return 0;
}
