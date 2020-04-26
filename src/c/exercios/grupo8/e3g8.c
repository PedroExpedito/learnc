/* Fazer uma rotina em "C" que recebe um vetor de números inteiros como
   parâmetro onde todos os valores exceto o último são positivos e devolve:
   - a média dos valores do vetor;
   - o menor valor do vetor (sem considerar o último)
   - o maior valor do vetor
 */
#include <stdio.h>
#define TAM 10
struct Result {
  float media;
  int min;
  int max;
};

struct Result f(int *array){

struct Result r;

  int z=array[0];
  int n=array[0];
  float sum;
  
  for(int i = 0; i < TAM - 1; i++){
    n = (array[i] < n) ? array[i] : n;

  }
  for(int i = 0; i < TAM; i++){
    z = (array[i] > z) ? array[i] : z;

    sum += array[i];

  }

  r.media = sum / TAM;
  r.min = n;
  r.max = z;
  
  return r;
}

int main(void){

  int array[TAM] = {10,9,8,7,6,5,4,3,2,-1};

struct Result r = f(array);
  printf("Media: %f, Minimo: %d,Maximo: %d \n", r.media,r.min,r.max);

}
