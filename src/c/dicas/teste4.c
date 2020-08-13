#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int entradas;
  scanf("%d", &entradas);

  int vetor[entradas];
  for(int i =0;i<entradas;i++)
  {
      scanf("%d",&vetor[i]);
  }
  int valor = 0;
  for (int i = 0; i < entradas; i++)
   {

        if (vetor[i] == 1 && vetor[i+1]==0 && vetor[i+2]==0)
        {
        valor++;
        i+=2;
        }

  }
  printf("%d\n", valor);
}
