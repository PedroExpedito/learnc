/* Fazer um programa em "C" que lê um string do teclado e se utiliza de uma
rotina recursiva para imprimir o string de maneira normal e de tráz para diante.
*/
#include <stdio.h>
int main(){
  int i=0;
  char frase[80];
  printf("Escreva uma frase.\n");
  scanf("%[^\n]",&frase);

  for(i=0;frase[i] != '\0';i++); //conta caracteres
  
  for(;i>=0;i--){
    printf("%c",frase[i]);
  }
  printf("\n");
  return(0);
}
