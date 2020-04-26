/* 1. Faça um programa em "C" que lê dois valores e imprime:
- se o primeiro valor for menor que o segundo, a lista de valores do primeiro até
o segundo;
- se o primeiro valor for menor que o segundo a lista de valores do segundo até
o primeiro em ordem decrescente;
- se ambos forem iguais a mensagem "valores iguais".
 */
#include <stdio.h>
int main(void)
{
  int num1,num2,contador;
  printf("Dijite o valor 1: \n");
  scanf("%d",&num1);
  printf("Dijite o valor 2: \n");
  scanf("%d",&num2);
  printf("\n");
  if (num1 == num2){
    printf("valores iguais\n");
  }
  else if (num1<num2){
    for (unsigned int i=num1;i <= num2;i++){
    printf("%d\n",i);
  }
  }
  else if (num1>num2){
    for (unsigned int i=num1;i >= num2;i--){
    printf("%d\n",i);
  }
  }
  return 0;
}