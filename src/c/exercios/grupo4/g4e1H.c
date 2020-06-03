/* 1. Fazer uma função que cacula a enésima potência de uma variável real x:
f(x, n) = xn
 */

#include <stdio.h>
#include <math.h>
/*
maybe should use quadmath.h and replace all long double with __float128.
*/

long double myPow(long double base, long double expoente)
{
  long double tmp = 1;
  for(volatile int i = 0; i < expoente; i++)
  {
    tmp = base * tmp;
  }
  return tmp;
}


int main(void) {
  
  printf("4 ^ 6 = %Lf \n", myPow(4.7, 4));

  //Better yet, just use pow() from math.h
  printf("4 ^ 6 = %f \n", pow(4.6, 4));
  //pow() is way more precise

  return 0;
}

