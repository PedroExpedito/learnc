/*1. Fazer uma função que retorna a soma, a diferença e o produto entre dois
  números.
 */
#include <stdio.h>
#include <string.h>

struct Result {
    int sum;
    int difference;
    int product;
};

struct Result f(int n,int y){
  struct Result r;
  r.sum = n + y;
  r.difference = n - y;
  r.product = n * y;
  return r;
  }
int main(void){
  struct Result r = f(5, 7);
  printf("sum is %d, difference is %d, productt is %d\n", r.sum,r.difference,r.product);
}
