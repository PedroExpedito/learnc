#include <stdio.h>
#include <string.h> //necessário para strcpy
int main (void)
{
  char nome[15];
  
  strcpy(nome, "Fulano de Tal");
  //strcpy(string_destino, string_origem);
  //note que a string de destino é nome
  //a string de origem é "Fulano de Tal"
  
  printf("Nome = %s", nome);
  
  return 0;
}
