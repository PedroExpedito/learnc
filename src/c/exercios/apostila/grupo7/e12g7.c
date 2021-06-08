/* 12. Fazer uma rotina em "C" que recebe um string como parâmetro e devolve o
endereço do primeiro caracter branco encontrado.
 */
#include <stdio.h>
int findspace(char *array);
int main(void){
  char ola[20] = "buenos dias";
  printf("%d",findspace(ola));
}
int findspace(char *array){
    for(int i=0;array[i];i++){
        if(array[i] == ' '){
            return i;
        }
    }
}
