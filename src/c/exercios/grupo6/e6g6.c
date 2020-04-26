/*.Fazer um programa que lê valores para uma matriz do tipo "float"de 5 linhas por
3 colunas e imprime a diferença entre a média dos elementos das colunas
pares e a média dos elementos das linhas ímpares.
*/
#include <stdio.h>
int main(void){
  float sum=0;
  float media[3];
  float array[5][3] = {{9,2,3},//0
                      {5,2,3},//1
                      {6,2,3},//2
                      {7,2,3},//3
                      {8,2,3},//4
                      };
  printf("Imprima Coluna:\n");
  for(unsigned short int i=0; i < 3;i++){
    for(unsigned short int j =0; j < 5;j++){
      sum+=array[j][i];
    }
    media[i] = sum/5;
    sum = 0;
  }
 float impar = (media[0]+media[2])/2;
 printf("diferença é de %f\n",impar - media[1]);

  }
