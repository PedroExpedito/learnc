// Abrir um arquivo para entra
// ler o conteúdo desse arquivo

#include <fstream>
#include <iostream>

using namespace std;

int main(void) {
  char path[] = "saida.txt";
  ofstream output(path);
  output << "Aprendendo IO\n";


  return 0;
}
