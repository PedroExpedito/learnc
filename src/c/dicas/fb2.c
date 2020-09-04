#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
  char regiao, vendedor;
  printf("Regioes:Leste,Oeste e Nordeste\n Informe a primeira letra da regiao:\n");

  regiao = getchar();
  regiao = toupper(regiao);
  printf("\n");
  getchar();

  switch (regiao) {

  case 'L':
    printf("Vendedores:Ricardo,Jose e Maria\n");
    printf("Informe a primeira letra do vendedor\n");
    vendedor = toupper(getchar());
    printf("\n");

    switch (vendedor) {
    case 'R':

      printf("Vendas:R$%d\n", 5000);
      break;

    case 'J':

      printf("Vendas:R$%d\n", 15000);
      break;

    case 'M':

      printf("Vendas:R$%d\n", 18000);
      break;

    } // end switch aninhado
    break;

  case 'O':
    printf("Vendedores:Rafael,Joana e Pedro\n");
    printf("Informe a primeira letra do vendedor\n");
    vendedor = toupper(getchar());
    printf("\n");

    switch (vendedor) {
    case 'R':

      printf("Vendas:R$%d\n", 2000);
      break;

    case 'J':

      printf("Vendas:R$%d\n", 8000);
      break;

    case 'P':

      printf("Vendas:R$%d\n", 18500);
      break;

    } // end switch aninhado
    break;

  case 'N':
    printf("Vendedores:Fabiana,Gabriela e Roberto\n");
    printf("Informe a primeira letra do vendedor\n");
    vendedor = toupper(getchar());
    printf("\n");

    switch (vendedor) {
    case 'F':

      printf("Vendas:R$%d\n", 3000);
      break;

    case 'G':

      printf("Vendas:R$%d\n", 6000);
      break;

    case 'R':

      printf("Vendas:R$%d\n", 1000);
      break;

    } // end switch aninhado
    break;
  } // end switch

  return 0;
}
