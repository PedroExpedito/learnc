#include <iostream>
/* Faça um algoritmo que leia o nome, o sexo e o estado civil de uma pessoa.
 * Caso sexo seja “F” e estado civil seja “CASADA”, solicitar o tempo de casada
 * (anos).
 */

int main (void) {
  std::string name;
  char genre;
  bool married = false;
  int marriedTime;
  std::cout << " Qual o seu nome ?" << std::endl;
  std::cin >> name;
  std::cout << " Qual o seu Sexo ? M para Masculina F para Feminino." << std::endl;
  std::cin >> genre;
  std::cout << "Estado Cívil 1 para casado e 0 para solteiro(a)" << std::endl;
  std::cin >> married;
  if ( genre == 'F' && married == true) {
    std::cout << "A quanto tempo é casada ? Reposta numerica por favor (ex: 10" << std::endl;
    std::cin >> marriedTime;
  }
}
