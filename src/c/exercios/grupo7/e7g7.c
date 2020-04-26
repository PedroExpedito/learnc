/* Implemente um rotina que faça a mesma coisa que a função "strcpy".*/

/*
#include <stdio.h>
char strcp(char *x, char *y);
int main(void){
  char bomdia[10];
  strcp(bomdia,"bom dia\n");
  printf("%s",bomdia);
}
*/

void strcp(char *x, char *y){
  int i=0;
  for (int i=0;y[i] != '\0';i++)
  {
    x[i] = y[i];
  }
}
   
