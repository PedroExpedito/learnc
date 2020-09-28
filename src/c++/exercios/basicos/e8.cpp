//Classes
#include<iostream> 
#include<string.h>

using namespace std;
typedef struct pessoa {
  char nome[100];
  int idade;
}t_pessoa;

int main(int argc, char * argv[]){
  t_pessoa p[3];
  
  strcpy(p[0].nome, "Antonio");
  p[0].idade = 26;

  cout << "Avião: " << p[0].nome << endl;
  cout << "Idade: " << p[0].idade << endl;
  t_pessoa pessoa;
  t_pessoa* ppessoa;
  ppessoa = &pessoa;


  ppessoa->idade = 26;

  cout << ppessoa->idade <<endl;


  return 0;
}
