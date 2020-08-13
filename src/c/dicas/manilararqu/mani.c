#include <stdio.h>
#include <stdlib.h>
int main(void) {
  FILE *file;
  file = fopen("teste.txt", "r");
  
  if(file == NULL){
    printf("Arquivo Não existe\n");
    exit(0);
  }  
  char *frase;
  
  while(fgets(frase,100,file) != NULL){
  printf("%s", frase);

  }  
  fclose(file);
 return 0;
}
