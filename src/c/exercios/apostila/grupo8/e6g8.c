/* Fazer um programa em "C" que lê uma lista de 20 produtos e e precós e
armazêna-os em um array do tipo da estrutura abaixo. O programa deve, em
seguida, ordenar o vetor em ordem alfabética de nome de produto e inflacionar
os produtos cujo valor for menor que 100 em 5%. Por fim a lista de
produtos/preços deve ser impressa.
OBS: usar uma rotina que recebe uma estrutura do tipo PROD com parâmetro
e atualiza o preço, uma que lê os dados para a estrutura do tipo PROD e outra
capaz de imprimir a estrutura.
typedef struct
{
char nome[80];
float preco;
} PROD;
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20

typedef struct {
  char nome[80];
  float preco;
} PROD;

void wMAX();
void rMAX();
void menu();
void readDataPROD();
void writeDataPROD();
void createPROD();
void printPROD();
void sortPROD();
void readDATA();
PROD prod[TAM];

int MAX = 0;

void readDATA(){
  FILE *file;
  file = fopen("max.txt", "r");
  if( file == NULL){
    wMAX();
    writeDataPROD();
  }
  else{
   rMAX();
   readDataPROD();
  }
}
void rMAX() {
  FILE *file;
  file = fopen("max.txt", "r");
  fscanf(file, "%d", &MAX);
  fclose(file);
}

void wMAX() {
  FILE *file;
  file = fopen("max.txt", "w");
  fprintf(file, "%d", MAX);
  fclose(file);
}

void readDataPROD() {
  FILE *file;
  file = fopen("prod.txt", "r");
  for (int i = 0; i < MAX; i++) {
    fscanf(file, "%s\n%f\n", prod[i].nome, &prod[i].preco);
  }
  fclose(file);
}

void writeDataPROD() {
  FILE *file;
  file = fopen("prod.txt", "w");
  for (int i = 0; i < MAX; i++) {
    fprintf(file, "%s\n%f\n", prod[i].nome, prod[i].preco);
  }
  fclose(file);
}

void createPROD() {
  float x=0;
  printf("Nome do Produto\n");
  scanf("%s", &*prod[MAX].nome);
  printf("Preço do Produto\n");
  scanf("%f", &x);
  prod[MAX].preco = x < 100 ? x : x + (x * 0.05);
  MAX++;
  wMAX();
  sortPROD();
}

void sortPROD() {
  char aux[80];
  for (int j = 0; j < MAX; j++) {
    for (int i = 0; i < MAX - 1; i++) {
      if (strcmp(prod[i].nome, prod[i + 1].nome) > 0) {
        j++;
        strcpy(aux, prod[i].nome);
        strcpy(prod[i].nome, prod[i + 1].nome);
        strcpy(prod[i + 1].nome, aux);
      }
    }
  }
  writeDataPROD();
}

void printPROD() {
  printf("\n IMPRIMINDO LISTA: \n\n");
  for (int i = 0; i < MAX; i++) {
    printf("%s\n%f\n", prod[i].nome, prod[i].preco);
  }
  printf("\nLista imprimida\n");
}

void menu() {
  printf("\n1 para inserir um produto\n2 Para imprimir a lista de produtos\n3 "
         "SAIR\n4 para ordenar a lista\n");
  int num;
  scanf("%d", &num);
  switch (num) {
  case 1:
    createPROD();
    menu();
  case 2:
    printPROD();
    menu();
  case 3:
    exit(0);
    menu();
  default:
    printf("Valor Não encontrado");
    menu();
  }
}

int main(void) {
  system("clear");
  readDATA();
  menu();
}
