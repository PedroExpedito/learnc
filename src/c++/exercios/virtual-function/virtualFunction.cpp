#include <iostream>
#define print(msg) std::cout << msg << std::endl
class Mother {
  public:
    virtual void showMessage() {
      print("I am Mother class");
    }
};

class Child: public Mother {
  public:
    virtual void showMessage() {
      print("I am Child class");
    }
};

void foo(Mother* p) {
  p->showMessage();
}

int main(void) {
  Mother m;
  Child c;

  foo(&m);
  foo(&c);

  // m.showMessage();
  // c.showMessage();

// ligação tardia: precisa colocar o virtual como prefixo
// ligação prematura: default

  return 0;
}
