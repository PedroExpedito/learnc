#include <iostream>
#include <string.h>

class Car{
  private:
    char name[100];
    char plate[10];
  public:
    void setName(const char *name) {
      strcpy(this->name, name);
    }
    char * getName(){
      return this->name;
    }

  protected:
};

int main(void) {
  Car car;
  car.setName("GOL");

  std::cout << car.getName() << std::endl;



  return 0;
}
