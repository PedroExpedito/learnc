/* Verificar se um arquivo Existe */
#include <stdio.h>

int main(void){
  FILE *file;
  file = fopen("teste.txt", "r");
  if ( file == NULL){
    printf("Arquivo Não existe");
  }
  else{printf("Arquivo existe");}
}
