/* Fazer uma rotina que recebe um string como parâmetro e imprime quantas
palavras (separadas por espaços em branco) o mesmo contém.
*/
#include <stdio.h>
int main(){
char frase[80];
int j=1;

printf("Dijite uma frase para saber quantas palavras tem separadas por espaço. \n");
scanf("%[^\n]s",&frase);

for(int i=0;frase[i];i++){
    if (frase[i] == ' ')
    {
        j++;
    }
    
}
j >= 2 ? printf("sua frase tem %d palavras\n",j) : printf("sua frase tem apenas uma palavra\n");;// operador ternario 
return j;
}
