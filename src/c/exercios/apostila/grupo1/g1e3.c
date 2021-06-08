/* Fazer um programa que solicita um número decimal e imprime o
correspondente em hexa e octal.
 */
#include <stdio.h>
int main(void)
{
  int num1,num2;
  printf("escreva o numero decimal para converter para hexa e octa: \n");
  scanf("%d", &num1);
  printf("em hexa é: %2X \n", num1);
  printf("em octa é: %o \n", num1);
  return 0;
}