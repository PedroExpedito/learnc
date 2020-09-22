#include <iostream>
#include <string>

int main(void) {
  std::string str = "Pedro";
  std::cout << str << std::endl;
  std::cout << str.length() << std::endl;
  std::cout << str.at(0) << std::endl;
  std::cout << str.back() << std::endl;
  std::cout << str.front() << std::endl;
  std::cout << str.append(" Expedito") << std::endl;
  std::cout << str << std::endl;



  return 0;
}
