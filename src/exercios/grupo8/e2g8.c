/*números.
  2. Fazer uma função em "C" que retorna a razão entre dois números. A função
  deve retornar pelo comando return o valor 1 se a operação foi possível e o
  valor 0 se a operação não foi possível (divisão por zero, por exemplo). O
  resultado da divisão deve retonar por um parâmetro por referência.
 */
#include <stdio.h>
struct Result {
  int p;
  float res;
};

struct Result f(float x, float n){
  struct Result r;
  if (n !=0){
    r.p = 1;
    r.res = x / n;
  }
  return r;
}
int main(void){
  struct Result r = f(4,2);
  printf("%d %f", r.p,r.res);

}
