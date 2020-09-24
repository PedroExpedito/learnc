// tudo retorno diferente de 0 é erro
// try catch throw

#include <iostream>

using namespace std;

int fat(int n)
{
  if( n < 0 )
    throw "Numero negativo!!";
  if (n == 0 || n == 1)
    return 1;
  return n * fat(n - 1);
}
int main(void) {
  try {
    cout << "Fatorial de 10: " << fat(-10) << endl;
  } catch(const char* err) {
    cerr << " Erro: " << err << endl;
  }
  catch(...) {
    cerr << "Erro Inesperado" << endl;
  }

}
