/*Fazer uma rotina que recebe como parâmetro um array de 5 posições contendo
as notas de um aluno ao longo do ano e devolve a média do aluno.
*/
/*a função atoi pertence a stdlib,lembrando que os argumentos devem ser passados na chamada da função exemplo executavel 1 2 3 4 5 */
#include <stdio.h>
#include <stdlib.h>
int main( int argc, char *argv[5]){
  int sum=0;
  for(unsigned short int i=0;i<=5;i++){
    sum += atoi(argv[i]);
  }
  printf("media de: %d\n",sum/5);
}

