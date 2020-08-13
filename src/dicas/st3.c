#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int MAX = 0;

void inserir();
void menu();

typedef struct {

  char lembretes[200];
  int dia;
  int mes;

} Lembrete;

Lembrete lembrete[TAM];

void menu(){
  int opt;

  printf("Escolha a opção\n");
  printf("0. Sair\n");
  printf("2. Exibir lembretes\n");
  printf("3. Adicionar lembrete\n");
  scanf("%d", &opt);

  switch (opt) {
  case 0:
    exit(0);
    break;

  case 1:
    break;

  case 2:
    break;

  case 3:
    inserir();
    break;

  case 4:
    break;

  default:
    exit(0);
  }

}
void inserir() {

  printf("Digite o dia:\n ");
  scanf("%d", &lembrete[MAX].dia);

  printf("Digite o mês(em número):\n ");
  scanf("%d", &lembrete[MAX].mes);

  printf("Digite o lembrete:\n ");
  scanf("%s", *&lembrete[MAX].lembretes);
}

void imprimir() {

  char *months[] = {"Janeiro",  "Fevereiro", "Março",    "Abril",
                    "Maio",     "Junho",     "Julho",    "Agosto",
                    "Setembro", "Outubro",   "Novembro", "Dezembro"};

  for (int i = 0 ; i < 1 ; i++) {
      printf("Dia %d: de %s acontecera%s", lembrete[MAX].dia,months[lembrete[MAX].mes],lembrete[MAX].lembretes);
    }
  }

int main() {
  menu();

}

