// vetor em CPP
#include <iostream>

using namespace std;

void my_strcat(char * dest, char * orig){
  char * nome1 = new char[100];
  char * nome2 = new char[100];
  char * resultado;



}
int my_strlen(char * str) {
  int tam = 0;

  while(*str != '\0'){
    str++;
    tam++;
  }
  return tam;
}
int main(int argc, char * argv[]){
  
  char nome[] = "Aprendendo c++";
  cout << "Dijite Seu Nome: ";
  cin >> nome;
  char sobrenome[] = "Aprendendo c++";
  cout << "Dijite Seu Nome: ";
  cin >> sobrenome;
  cout << my_strlen(nome);


}

