/*8. Fazer um programa em "C" que solicita um número inteiro e soletra o mesmo
na tela.
Ex:
124: um, dois, quatro
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void soletra(char *number);
int main(void)
{
  int tam = 10;
  char number[tam];
  printf("Dijite um numero: ");
  scanf("%[0-9]s", &number);
  setbuf(stdin, NULL);
  soletra(number);
  return 0;
}

void soletra(char *number)
{
  printf("Os numeros dijitados foram: ");
  for (int i = 0; i < strlen(number); i++)
  {

    switch (number[i])
    {
    case '0':
      printf("Zero, ");
      break;
    case '1':
      printf("Um, ");
      break;
    case '2':
      printf("Dois, ");
      break;
    case '3':
      printf("Trés, ");
      break;
    case '4':
      printf("Quatro, ");
      break;
    case '5':
      printf("Cinco, ");
      break;
    case '6':
      printf("Seis, ");
      break;
    case '7':
      printf("Sete, ");
      break;
    case '8':
      printf("Oito, ");
      break;
    case '9':
      printf("Nove, ");
      break;

    default:
      break;
    }
  }
  printf("\n");
}
