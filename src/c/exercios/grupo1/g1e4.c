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
  printf("Digite o graus em fahrenheit para converter para celcius: ");
  scanf("%lf", &x);
  printf("em celsius %lf \n",(x - 32.0) * 5.0/9.0);

  /*
  x is double, if either operand is float, the other will be converted to float. 
  Same thing happens in the 5/9 part, so there's no difference. Everything is 
  implicited converted.
  */
  printf("Digite o graus em fahrenheit para converter para celcius: ");
  scanf("%lf", &x);
  //that's why the compiler doesn't warn when you use "%lf", because the result
  //is expected to be a double.
  printf("em celsius %f \n",(x - 32) * 5/9);


  return 0;
}
