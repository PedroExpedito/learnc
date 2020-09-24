#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
  char path[] = ("fail.txt");
  ifstream in(path);
  char c;

  while(1) {
    in >> c;
    if(in.fail())
      break;
    cout << c;
  }

}
