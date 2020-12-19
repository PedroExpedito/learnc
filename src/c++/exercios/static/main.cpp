// Uma variavel estatica tem o mesmo tempo de vida mantendo seus
// valores em chamadas a função, retendo as informações.

#include <iostream>

int static_function() {
  static int a = 1;
  return a++;
}
int main(void) {
  std::cout << static_function();
  std::cout << static_function();
  std::cout << static_function();

}
