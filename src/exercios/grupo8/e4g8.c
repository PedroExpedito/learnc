/*4. Fazer uma função para ler e retornar o valor das 3 notas de um aluno.*/
#include <stdio.h>

struct Notas {
  int nota1;
  int nota2;
  int nota3;
};

struct Notas f(int x, int n, int y){
  struct Notas r;
  r.nota1 = x;
  r.nota2 = n;
  r.nota3 = y;
  return r;
}
int main(void){
  struct Notas r = f(2,3,4);
  printf("%d,%d,%d\n", r.nota1,r.nota2,r.nota3);
}
