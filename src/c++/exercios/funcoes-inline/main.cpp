#include <iostream>

// funções inline:
//
// O compilador copia o código da função aonde ela é chamada isso pode ser um pouco mais
// rápido.  Porém a cada vez que ela é chamada ela aumenta o tamanho do binario
// e o espaço em memoria
//
//

using namespace std;

inline void foo()
{
  cout << "Aprendendo C++\n" << endl;
}

int main(int argc, char*argv[]) {
  foo();
}
