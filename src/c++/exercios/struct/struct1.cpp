#include <iostream>

struct People {
  People(int age);

private:
  int age;
public:
  void set_age(int age) { this->age = age; }
  int getAge() { return this->age; }
};

People::People(int age) { this->age = age; }

int main(void) {

  struct People p(10);

  std::cout << p.getAge() << std::endl;
}
