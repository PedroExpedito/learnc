#include <stdio.h>

int main(void) {
  int membros;
  printf("Quantos membros a na familia ?\n");
  scanf("%d", &membros);
  int IdadeMembros[membros];
  for (int i = 0; i < membros; i++ ) {
    printf("Insira a idade do membros da familia\n");
    scanf("%d", &membros);
  }
}
