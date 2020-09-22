#include <iostream>
/* Parametros opcionais  C também suporta */

using namespace std;

int quad(int num = 1) {
  return num * num;
}
int main(void) {
  int num = 10;
  cout << quad() << endl;
}
