/*Construir um programa em "C" que implementa uma agenda eletrônica. O
programa deve ter um menu com as seguintes opções:
1- Entrar um nome na agenda
2- Imprimir na tela os dados de uma das pessoas cadastradas (consulta por
nome)
3- Imprimir na impressora a lista dos nomes que começam pela letra indicada
*/
/*Eu mudei para agenda telefonica, agenda eletronica é estranho existe varias com muitas funcionalidades diferentes*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int MAX=0;

void menu();
void printAgenda();
void createPeople();
int readData();
void writeData();
void searchPeople();

typedef struct {
  char name[100];
  char number[20];
} Agenda;

Agenda agenda[100];

int main(void){
  if (readData() != 0) {
    writeData();
  }
  menu();
}
int readData() {
  FILE *file;
  file = fopen("agenda.txt", "r");
  if (file != NULL) {
    fscanf(file, "%d\n", &MAX);
    for (int i = 0; i < MAX; i++) {
      fscanf(file, "%s\n%s\n", agenda[i].name, agenda[i].number);
    }
  } else {
    return 1;
  }
  fclose(file);
  return 0;
}

void writeData() {

  FILE *file;
  file = fopen("agenda.txt", "w");
  fprintf(file, "%d\n", MAX);
  for (int i = 0; i < MAX; i++) {
    fprintf(file, "%s\n%s\n", agenda[i].name, agenda[i].number);
  }
  fclose(file);
}

void createPeople(){

  printf("Insira o nome: \n");
  scanf("%s",*&agenda[MAX].name);
  printf("Insira o numero: \n");
  scanf("%s",*&agenda[MAX].number);
  MAX++;
  writeData();
}
void searchPeople(){
  char name[100];
  printf("Insira o nome para pesquisar\n");
  scanf("%s",*&name);
  for (int i = 0; i < MAX; i++){
    if( strcmp(name, agenda[i].name) == 0 ){
      printf("\nNome Encontrado de %s\nNumero: %s \n", agenda[i].name, agenda[i].number);
    }
  }
}
void searchPeopleChar(){
  char name;
  printf("Insira uma letra para pesquisar\n");
  scanf("%c",&name);
  for (int i = 0; i < MAX; i++){
    if (agenda[i].name[0] == name){
      printf("%s\n",agenda[i].name);
    }
  }
}

void menu(){
  int x ;
  printf("\n\nMenu\n1 para insirerir uma pessoa na lista\n2 para procurar o numero na lista por nome\n3 para pesquisar pela primeira letra do nome\n4 para sair\n");
  scanf("%d",&x);
  switch ( x ){
    case 1:
      createPeople();
      menu();
    case 2:
      searchPeople();
      menu();
    case 3:
      setbuf(stdin, NULL);
      searchPeopleChar();
      menu();
    case 4:
      exit(0);
    default:
      printf("Valor Desconhecido");
      exit(1);
  }

}
