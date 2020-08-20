#include <stdio.h>
#include <stdlib.h>
typedef struct pessoa
{
char* nome;
int idade;
}Pessoa;

typedef struct lista_pessoa
 {
 Pessoa p;
 }ListaPessoa;

 int main(void){

 ListaPessoa *l;
 l=(ListaPessoa*)malloc(sizeof(ListaPessoa));
 if(l == NULL) exit(1);

 Pessoa p1;
 p1.nome = "Fulano";
 p1.idade = 25;

 l->p = p1;

 free(l);
 printf("%s\n",p1.nome);
 return 0;
 }