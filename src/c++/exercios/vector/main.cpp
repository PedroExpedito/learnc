#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  //C mode int vector[4] = { 0 , 1, 2, 3 };
  vector<int> vetor(1);

  vetor[0] = 10;
  // vetor.push_back(0);
  // cout << vetor[0] << endl << vetor.size() << endl;

  // interador é um objeto para analizar um container

  vector<int>::iterator it;

  for(it = vetor.begin(); it != vetor.end(); it++)
  {
    cout << *it << endl;
  }

  cout << *vetor.begin() << endl;
  cout << *(--vetor.end()) << endl;

  // interador reverso
  //

  vector<int>::reverse_iterator hit;

  int i = 0;

  for(hit = vetor.rbegin(); hit != vetor.rend(); hit++)
    *hit = ++i;

}

