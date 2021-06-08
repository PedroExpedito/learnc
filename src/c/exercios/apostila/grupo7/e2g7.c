/*Fazer um programa em "C" que lê um string contendo palavras separadas por
um espaço em branco cada e as imprime uma abaixo das outras.
*/
#include <stdio.h>
int main(){
    char frase[80];
    printf("Escreva uma frase.\n");
    scanf("%[^\n]",&frase);
      for(int i=0; frase[i] != '\0';i++){
      if (frase[i] == ' '){
        printf("\n");
      }
      else{printf("%c",frase[i]);}

}
  printf("\n");  
  return 0;
}
