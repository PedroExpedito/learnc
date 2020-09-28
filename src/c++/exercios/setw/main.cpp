#include <iostream>
#include <iomanip>
#include <string>

// Operador setw ele pega um fluxo e coloca dentro de um campo de N caracteres e
// justifica a direita

using namespace std;


using std::left;

class People {
  public:
    string name;
    int age;
    People(const string& name, const int& age) {
      this->name.assign(name);
      this->age = age;
    }
};

int main(void) {
  People p1("Pedro",20);
  People p2("Marcos", 30);
  People p3("Felipe", 33);

  cout << setw(20) << left <<  p1.name << setw(10) << p1.age << endl;
  cout << setw(20) << setfill('.') << p2.name << setw(10) << p2.age << endl;
  cout << setw(20) << p3.name << setw(10) << p3.age << endl ;

  return 0;
}
