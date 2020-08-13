// Escopo de classes
// moduloes em C simplesmente para todos os arquivos.c para o compilador

#include <stdlib.h> // é uma macro que inclui um arquivo
#include <stdio.h>

int i;
void func(void){
  for(i = 0; i < 3; i++)
    printf("%d\n",i);
}

int main(void){
  i++;
  func();
}

