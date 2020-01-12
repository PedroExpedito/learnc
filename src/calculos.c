#include "calculos.h"

float quadrado(float x){
    return x * x;
}
float cubo(float x){
    return x * x * x;
}
int soma(int x,int n){
    return x + n;
}
int subtracao(int x,int n){
    return x - n;
}
int pot(int numero,int expoente){
  int i, resultado=1;	//resultado começa com 1 para caso expoente=0, não entrara no laço e retornará 1
  for (i=1; i<=expoente; i++){
    resultado *= numero;	//resultado é multiplicado pelo numero
  }
  return resultado;
}