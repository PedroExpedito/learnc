#include <iostream>
#include <map>

// guarda chave valor

// usando C++ 20
// https://en.cppreference.com/w/cpp/container/map

using namespace std;

int main(int argc, char *argv[]) {

  map<string, int> mapa = {

    {"pedro", 0},
    {"maria", 1},
    {"antonia",2}
  };

  for( const auto& [key, value] : mapa) {
    cout << key << value << endl;
  }

  cout << mapa.size() << endl;


  return 0;
}
