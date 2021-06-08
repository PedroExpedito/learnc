#include <stdio.h>
#include <stdlib.h>
#define T 3
struct aluno {char nome [100];int idade;int ra;float mensal;};
struct aluno ler() {
  struct aluno a;
  printf("\n----Digite seu nome:---- \n");
  fflush(stdin);
  scanf("%s",&a.nome);
  printf("----Digite sua idade:---- \n");
  scanf("%d", &a.idade);
  printf("----Digite seu RA:---- \n");
  scanf("%d", &a.ra);
  printf("----Digite sua mensalidade:---- \n");
  scanf("%f", &a.mensal);
  printf("\n============================\n");
  return a;
}
void imprime(struct aluno a[T]) {
  int x;
  for (x = 0; x < T; x++) {
    printf("\t Nome: %s\n", a[x].nome);
    printf("\t Idade: %d\n", a[x].idade);
    printf("\t RA: %d\n", a[x].ra);
    printf("\t Mensalidade: %.2f\n", a[x].mensal);
  }
}
int main() {
  int x;
  char caminho[] = "aluno.txt", caractere;
  FILE *arquivo;
  arquivo = fopen(caminho, "w");
  struct aluno a[T];
  if (arquivo == NULL) {
    printf("Erro ao criar arquivo.\n");
  } else {
    for (x = 0; x < T; x++) {
      a[x] = ler();
      fprintf(arquivo, "Nome: %s\nIdade: %d\nRA: %d\nMensalidade: %.2f\n\n\n",
              a[x].nome, a[x].idade, a[x].ra, a[x].mensal);
      printf("\tArquivo gravado com sucesso.\n");
    }
    fclose(arquivo);
  }
  imprime(a);
  return 0;
}
