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
#include <stdio.h>
#include <string.h>
#define TAM 10
#include<stdlib.h>
void create();
void writeData();
void readData();
void menu();
void findChar();
typedef struct {
  char nome[30];
  char endereco[100];
  char fone[10];
  long int CEP;
} Agenda;

Agenda people[10];
int MAX = 0;

int main() {
  readData();
  menu();
}
void writeData() {
  FILE *file;
  file = fopen("data.txt", "w");
  for (int i = 0; i < TAM; i++) {
    fprintf(file, "%s\n%s\n%s\n%ld", people[i].nome, people[i].endereco,
            people[i].fone, people[i].CEP);
  }
  fclose(file);
  FILE *file2;
  file2 = fopen("max.txt", "w");
  fprintf(file2, "%d", MAX);
  fclose(file2);
}
void readData() {
  FILE *file;
  file = fopen("data.txt", "r");
  if (file == NULL) {
    printf("ERRO FILE DONT EXIST");
  } else {
    for (int i = 0; i < TAM; i++) {
      fscanf(file, "%s\n%s\n%s\n%ld\n", people[i].nome, people[i].endereco,
             people[i].fone, &people[i].CEP);
    }
  }
  FILE *file2;
  file2 = fopen("max.txt", "r");
  if (file2 != NULL) {
    fscanf(file2, "%d", &MAX);
    fclose(file2);
  }
}
void printData() {
  printf("\nIMPRIMIMINDO....\n");
  for (int i = 0; i < MAX; i++) {
    printf("nome:%s\nendereco:%s\nfone:%s\nCEP:%ld\n\n", people[i].nome,
           people[i].endereco, people[i].fone, people[i].CEP);
  }
  menu();
}
/*void searchdata(char *name, Agenda *people) {
  int i = 0;
  for (i = 0; i < MAX; i++) {
    if (strcmp(name, people[i].nome) == 0) {
      printf("AQUI NA LISTA TEM\n\n");
      printf("Nome: %s\n", people[i].nome);
      printf("Endereço:  %s\n", people[i].endereco);
      printf("Fone: %s\n", people[i].fone);
      printf("CEP: %ld\n", people[i].CEP);
      } else if (i >= MAX -1) {
      printf("Não foi encontrado\n");
    }
  }
}*/
void create() {
  int x = MAX;
  printf("nome: \n");
  scanf("%s", *&people[x].nome);
  printf("endereço: \n");
  scanf("%s", *&people[x].endereco);
  printf("fone: \n");
  scanf("%s", *&people[x].fone);
  printf("CEP\n");
  scanf("%ld", &people[x].CEP);
  setbuf(stdin, NULL);
  MAX++;
  writeData();
  menu();
}
void findChar() {
  printf("\nDijite a primeira letra: ");
  char p;
  scanf("%c", &p);
  setbuf(stdin, NULL);
  for (int i = 0; i < MAX; i++) {
    printf("\n\nNOMES: começando com %c\n",p);
    if (people[i].nome[0] == p) {
      printf("%s\n", people[i].nome);
    }
  }
  menu();
}

void menu() {
  printf("\n");
  printf("1 para entrar um novo nome na agenda.\n2 para  imprimir na tela os "
         "dados de uma das pessoas cadastradas \n3 Imprimir a lista de nomes "
         "cadastrados que comecem pela letra indicada.\n4 para Fim \n\n");
  int num;
  scanf("%d", &num);
  switch (num) {
  case 1:
    create();
    break;

  case 2:
    setbuf(stdin, NULL);
    printData();
    break;

  case 3:
    setbuf(stdin, NULL);
    findChar();
    break;
  case 4:
    //setbuf(stdin, NULL);
    writeData();
    printf("SAINDO...\n\n");
    exit(1);

  default:
    printf("Valor invalido!\n");
  }
}
