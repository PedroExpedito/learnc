// type_info::name example
#include <iostream>       // std::cout
#include <typeinfo>       // operator typeid

int main() {
  int i;
  int * pi;
  char ola[] = "ola";

  std::cout << "int is: " << typeid(int).name() << '\n';
  std::cout << "  i is: " << typeid(i).name() << '\n';
  std::cout << " pi is: " << typeid(pi).name() << '\n';
  std::cout << "*pi is: " << typeid(*pi).name() << '\n';
  std::cout << "ola is: " << typeid(ola).name() << '\n';

  return 0;
}
