// Abrir um arquivo para entra
// ler o conteúdo desse arquivo

#include <fstream>
#include <iostream>

using namespace std;

int main(void) {
  char path[] = "teste.txt";
  ifstream in(path);

  string text;

  char c = in.get();
  text.push_back(c);

  cout << "Mostrando cada char:\n";

  while(in.good()) {
    cout << c;
    c = in.get();
    text.push_back(c);
  }

  cout << "String:" << text << endl;


  return 0;
}
