/* 5. Fazer um programa em "C" que solicite 2 números e informe:
a) A soma dos números;
b) O produto do primeiro número pelo quadrado do segundo;
c) O quadrado do primeiro número;
d) A raiz quadrada da soma dos quadrados;
e) O seno da diferença do primeiro número pelo segundo;
f) O módulo do primeiro número.
 */
#include <stdio.h>
#include <math.h>/* Precisa usar a tag -lm no gcc para poder usar essa biblioteca */

int main(void)
{
  int num1,num2;
  printf("dijite o numero 1: ");
  scanf("%d",&num1);
  printf("dijite o numero 2: ");
  scanf("%d",&num2);

  printf("soma dos numeros: %d\n", num1+num2);
  printf("soma do numero1 somado com o quadrado do segundo: %d\n", num1+(num2*num2));
  printf("quadrado do primeiro numero: %d\n", num1*num1);
  printf("soma dos quadrados do primeiro e segundo numero: %d\n", (num1*num1)+(num2*num2));
  printf("o modulo do primeiro numero: %d\n", num1);
  printf("Seno da diferença do primeiro número pelo segundo: %lf\n", sin((double)num1-num2));
  return 0; 
}