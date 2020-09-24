#include <iostream>
#include <string>

// sobrecarga do operador =

using namespace std;

class People {
  public:
    string name;
    int id;
    People(string newName, int newId) {
      this->name.append(newName);
      this->id = newId;
    }
    ~People() {
      name.clear();
    }
    void appendName(string newName) {
      this->name.append(newName);
    }
};

int main(void) {
  People p1("Pedro",2), p2("expedito",3);
  p1 = p2;// Copia
  cout << "P1: " << p1.name << endl;
  cout << "P2: " << p2.name << endl;
  p1.appendName(" Oliveira");
  cout << "P1: " << &p1.name << endl;
  cout << "P2: " << &p2.name << endl;

}

