#include <iostream>
#include <string.h>
#define print(msg) ( std::cout << msg << std::endl )

//faz com que dijite menos cógido
void my_strcpy(char *dest, const char *copy) {
  int i = 0;
  while( copy[i] != '\0' ) {
    dest[i] = copy[i];
    i++;
  }
  std::cout << dest[i] << std::endl;
}
class Animal {
  protected:
    char *name;
    bool fly;
    int paw;
  public:
    Animal(const char *name) {
      int size = strlen(name) + 1;
      this->name = new char[size];
      my_strcpy(this->name,name);
      fly = false;
      paw = 0;
    }
    ~Animal() {
      delete[] name;
    }

    char *getName() {
      return name;
    }
    bool getFly() {
      return this-> fly;
    }
    int getPaw() {
      return this->paw;
    }
};
class Dog : public Animal {
  protected:
    int age;
  public:
    Dog(const char* name) : Animal(name) {
      age = 0;
    }
    int getAge() {
      return this->age;
    }
    ~Dog() {
    } // so pode destruir dados intrincicos a classe e nada da classe PAI
};
int main(void) {
  Dog p("rex");

  std::cout << "Name:" << p.getName() << std::endl;

  return 0;
}
