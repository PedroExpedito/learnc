/* O CPP permite varias funções com o mesmo nome diferenciando se pelos argumentos não sabia que existia isso sera que tem no C ?, existe com apartir do C11 porém e gambiarra e também da para fazer tudo em C e compilar com o compilador de c++ para poder usar oque tem dede dahora no c++ */
#include <iostream>

using namespace std;

void message(int x){
  cout << "Number: " << x << endl;
}
void message(){
  cout << "Não tem numero " << endl;
}
int main(void){
  message();
}
