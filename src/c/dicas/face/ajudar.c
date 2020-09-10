#include <stdio.h>
#include <stdlib.h>
#define REGISTROS 17
#define PATH "dados.txt"

void ERROR(char *msg, int code) {
  printf("%s\n", msg);
  exit(code);
}

/* Passos:
 * Ler o arquivo e colocar os dados em uma estrutura
 * Ordenar os dados pelo numero - Não foi preciso porque os dados.txt já estão ordenados
 * implementar busca binaria
 *
 * referencias:
 *
 * Wikipedia muito bom: https://pt.wikipedia.org/wiki/Pesquisa_bin%C3%A1ria
 *
 * Man : https://www.man7.org/linux/man-pages/man3/scanf.3.html
 *
 * */



typedef struct {
  int numero;
  char nome[50];
  int idade;
  int salario; // no caso o salario do dados.txt é inteiro
} Pessoa ;

Pessoa pessoa[REGISTROS];

int readData() {
  FILE *file;
  file = fopen(PATH, "r");

  if (file != NULL) {
    for (int i = 0; i < REGISTROS; i++) {
      fscanf(file, "%d %s %d %d\n", &pessoa[i].numero, pessoa[i].nome, &pessoa[i].idade, &pessoa[i].salario);
 //     printf("%d %s %d %d\n", pessoa[i].numero, pessoa[i].nome, pessoa[i].idade, pessoa[i].salario);
    }
  } else {
    ERROR("Erro ao abrir arquivo", 1);
  }
  fclose(file);
  return 0;
}

int PesquisaBinaria (int chave)
{
     int inf = 0;     // limite inferior (o primeiro índice de vetor em C é zero)
     int sup = REGISTROS-1; // limite superior (termina em um número a menos. 0 a 9 são 10 números)
     int meio;

     while (inf <= sup)
     {
          meio = (inf + sup)/2;
          if (chave == pessoa[meio].numero)
               return meio;
          if (chave < pessoa[meio].numero)
               sup = meio-1;
          else
               inf = meio+1;
     }
  return -1;
}
int printPessoa(int i) {
  if ( i < 0) {
    return -1;
  }
  printf("%d %s %d %d\n", pessoa[i].numero, pessoa[i].nome, pessoa[i].idade, pessoa[i].salario);
  return 0;
}

int main(void) {
  readData();
  int posi = PesquisaBinaria(1440); // passei o numero do Cristiano do dados.txt
  if ( posi < 0 ) {
    ERROR("Não á este numero na lista", 1);
  }
  printPessoa(posi);
  return 0;
}
