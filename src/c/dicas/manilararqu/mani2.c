#include <stdio.h>
#include <stdlib.h>

int main(void) {

  FILE *file;
  file = fopen(".teste.txt", "w");
  fclose(file);
  file = fopen(".teste.txt", "a");
  
  if(file == NULL){
    printf("Arquivo Não existe\n");
    exit(0);
  }
while(1){  
 fprintf(file, "Primeira Linha\n");
}
    
  fclose(file);
 return 0;
}
