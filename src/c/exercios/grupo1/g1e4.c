/* 4. Fazer um programa em "C" que pergunte um valor em graus Fahrenheit e
imprime no vídeo o correspondente em graus Celsius usando as fórmulas que
seguem.
a) Usar uma variável double para ler o valor em Fahrenheit e a fórmula
C=(f-32.0) * (5.0/9.0).
b) Usar uma variável int para ler o valor em Fahrenheit e a fórmula
C=(f-32)*(5/9).
 */
/* Enunciado confuso então fiz na versão "a" */

#include <stdio.h>
int main(void)
{
  double x;
  printf("Dijite o graus em fahrenheit para converter para celcius: ");
  scanf("%lf", &x);
  printf("em celsius %.2lf \n",(x - 32.0) * 5.0/9.0);
  return 0;
}