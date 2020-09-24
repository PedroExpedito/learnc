#include <stdio.h>

struct Fraction {
  float n; //numerador
  float d; //denominador
};

typedef struct Fraction fraction;

fraction mult(fraction a, fraction b)
{
  fraction resultado;
   resultado.d = a.d * b.d;
   resultado.n = a.n * b.n; //verificar o numerador testar
  return resultado;
}


int main(void) {

  fraction fraction1 = { 15 , 2 };
  fraction fraction2 = { 2 , 1 };
  fraction produto;

  produto = mult(fraction1, fraction2);

  printf("O produto Final é=> %.2f / %.2f \n", produto.n, produto.d);



  return 0;
}
