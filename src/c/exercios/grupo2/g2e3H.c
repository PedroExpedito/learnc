/* 3. Fazer um programa em "C" que lê o preço de um produto e inflaciona esse
preço em 10% se ele for menor que 100 e em 20% se ele for maior ou igual a
100.
OBS: não use o comando "if" ou o operador de condição "?".
 */
#include <stdio.h>
int main(void){
float x=0;
printf("Dijite o valor do produto: ");
scanf("%f",&x); 
printf("%.2lf",(x * (1.1 + 0.1 * ((x >= 100)))));   
}