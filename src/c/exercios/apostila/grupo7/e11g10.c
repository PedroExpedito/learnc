/*11. Escreva uma função em "C" que receba um string um caracter e o índice de
  uma posição do string como parâmetro e insira o caracter na posição
  "empurrando" todos os demais para o lado.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void istchar(char *word,char cha,int p);
int main(){
  char lobo[20] = "lobo";
  istchar(lobo,'z',1);
  printf("%s",lobo);
}
void istchar(char *word,char cha,int p){
  char aux[20];
  aux[p] = cha;
  for(int i= 0;i <= strlen(word) + 1;i++){
      if (i < p){
      aux[i] = word[i];
      }
      else if( i == p){
        aux[i+1] = word[i];
        aux[i] = cha;
      }
      else{
        aux[i+1] = word[i];
      }
  }
  strcpy(word,aux);
}
