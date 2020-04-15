/*5. Fazer uma rotina que aguarda um string do teclado e retorna o valor 1 se o
string digitado foi "SIM" e 0 se o string digitado foi "NAO". A rotina só deve
retornar alguma coisa se o string digitado for "SIM" ou "NAO".
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int condition(int x){return x;}

void main(){
  char cond[4]="nul\0";
  printf("Dijite SIM ou NAO \n");
  scanf("%[A-Z]s",&cond);

  if(strcmp (cond, "SIM") == 0){
    condition(1);
  }
  else if(strcmp (cond, "NAO") == 0){
    condition(0);
  }
  }

  
