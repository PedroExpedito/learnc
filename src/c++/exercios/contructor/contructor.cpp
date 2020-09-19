#include <iostream>

// Contrutor contrui a classe KK
// Destrudores servem para desalocar da memoria
// Os objetos são destruidos na ordem inversa que são contruidos
// primeiro a entrar ultimo a sair.
//
// Sobrecarga de Construtores


void my_strcpy(char*destino,const char*copy) {
  int i = 0;
  while(copy[i] != '\0') {
    destino[i] = copy[i];
    i++;
  }
}
class People {
  protected:
    char name[100];
    int age;
    int* relatives;
  public:
    People() {
      relatives = new int[100];
    }
    People(const char*name) {
      my_strcpy(this->name, name);
      this->age = 0;
      relatives = new int[100];
    }
    People(const char* name,int age) {
      my_strcpy(this->name, name);
      this->age = age;
      relatives = new int[100];
    }
    ~People() {
      std::cout << "Destruct" << std::endl;
      delete[] relatives;
    }

    char * getName() {
      return name;
    }

    int getAge() {
      return age;
    }

};

int main(int argc, char **argv) {
  People p;
  return 0;
}
