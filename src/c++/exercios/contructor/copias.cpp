#include <iostream>
#include <string.h>

// Copia profunda

class Student {
  private:
    int age;
    char *name;
  public:
  Student(const char* name) {
    std::cout << "Contruindo" << std::endl;
    this-> age = 0;
    int size = strlen(name) + 1;
    this->name = new char[size];
    strcpy(this->name, name);
  }

  // O contrutor de copia recebe o endereço de memoria de uma classe do mesmo tipo
  // que ele usando sobrecarga de ponteiros

  Student(const Student& s) {
    std::cout << "Contruindo Copia..." << std::endl;
    int size = strlen(s.name) + strlen("Copia de ") +1;
    this->name= new char[size];
    strcpy(this->name, "Copia de ");
    strcat(this->name, s.name);
  }
  ~Student() {
    std::cout << "Destruindo" << std::endl;
    delete[] name;
  }
  const char* getName() {
    return this->name;
  }
  int getAge() {
    return this->age;
  }

};
void copy(Student s) {
  std::cout << s.getName() << std::endl;
}

int main(void) {
  Student pedro("pedro");
  copy(pedro);
  std::cout << "Idade: "<< pedro.getAge() << pedro.getName() << std::endl;
  return 0;
}
