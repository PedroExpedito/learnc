/* Porque não estou conseguindo contar quantos números IMPAR foram digitados? */
#include <stdio.h>
int main()
{
  int matriz[3][3];
  int imp=0;
    for(int i=0;i < 3;i++){
      for(int j=0;j < 3;j++){
        printf("Dijite o valor da matriz [%d],[%d]:",i,j);
        scanf("%d",&matriz[j][i]);
        printf("\n");
        if((matriz[j][i] % 2) !=0){
          imp++;
        }
      }
    }
  printf("\nA quantidade de numeros impar: %d\n", imp);
}
