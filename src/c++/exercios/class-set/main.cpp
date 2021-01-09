// é uma estrutura conjunto aonde não tem elementos repetidos
//
// quando utilizar set ?
// Quando vamos ter um conjunto que não há elementos repetidos

#include <iostream>
#include <set>

using namespace std;
int main() {
  int vector[] = {10, 20, 10, 30, 40, 50};
  set<int> myset (vector, vector + 5);

  set<int>::iterator it = myset.begin();

  while(it != myset.end()) {
    cout << *it << endl;
  }
  return 0;
}


