/*5. Construir um programa em "C" que implementa uma agenda eletrônica. O
  programa deve ter um menu com as seguintes opções:

 * Entrar um novo nome na agenda.

 * Imprimir na tela os dados de uma das pessoas cadastradas (conforme
 solicitação).

 * Imprimir a lista de nomes cadastrados que comecem pela letra indicada.

 * Fim

 Cada entrada da agenda deve ter os seguintes campos:

 char nome[30];
 char endereco[100];
 char fone[10];
 long int CEP;

Obs: a agenda deve ter capacidade para 100 entradas.
 */
#include<stdio.h>
#include<string.h>

void create();
typedef struct {
  char nome[30];
  char endereco[100];
  char fone[10];
  long int CEP;
} Agenda;


void printdados(char *name, Agenda *people);
int main(void){

  int option;
  printf(" 1 para  Entrar com um novo nome na agenda  \n 2 para para imprimir dados da pessoa conforme o nome\n");
  scanf("%d",&option);
  create(); 
}
void create(){
  Agenda people[100];
  printf("nome: \n");
  scanf("%s",&people[0].nome);
  printf("endereço: \n");
  scanf("%s",&people[0].endereco);
  printf("fone: \n");
  scanf("%d",&people[0].fone);
  printf("CEP\n");
  scanf("%d",&people[0].CEP);
  printf("\n\n%s\n",people[0].nome);
  printdados("Pedro",people);

}
void printdados(char *name, Agenda *people){
  for (int i = 0; i < 100; i++){
    if (strcmp(name,people[i].nome) == 0){
     printf("TEM UMA\n"); 
    }
  }
}

