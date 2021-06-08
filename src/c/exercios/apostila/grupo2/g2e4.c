/* 4. Fazer um programa que lê um valor, um operador (+,-,*,/) e outro valor e
imprime o resultado da expressão:
<valor 1> <operador> <valor 2>
 */
#include <stdio.h>
int main(void)
{
 int a,b;
 char op[1];
 printf("calculadora: \n");
 scanf("%d",&a);
 scanf(" %c",&op);
 scanf("%d",&b);
 printf("calculando...\nResultado: ");

 switch ( op[0] )
 {
 case '+':
   printf("%d\n",a+b);
   break;
  case '-':
    printf("%d\n\n", a - b);
    break;
  case '*':
    printf("%d\n\n", a * b);
    break;
  case '/':
    printf("%d\n\n", a / b);
    break;
 
 default:
    printf("ERRO\n");
   break;
 }
 printf("fim\n");
 return 0;
}