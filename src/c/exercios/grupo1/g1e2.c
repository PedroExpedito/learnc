/*  Fazer um programa em C que imprime uma tabela com a tabuada de 1 a 9*/
#include <stdio.h>
int main(void)
{
  int num1,num2;
  for (num1 = 0; num1 <= 10; num1++){
      num2 = num1 * 9;
      printf("9x%d=%d\n",num1,num2);
  }
  return 0;
  }