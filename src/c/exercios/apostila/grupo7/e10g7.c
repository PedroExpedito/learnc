/*10. Escrever uma função que recebe um string e um caracter como parâmetro e
  remove todas as ocorrências do caracter do string.
 */
#include <stdio.h>
#include <string.h>
void rmchar(char *word,char c);
int main(){
  char palavra[100] = "papepipopupapepipopu";
  rmchar(palavra, 'p');
  printf("%s\n",palavra);
  return 0;
}
void rmchar(char *word,char c){
  int j=0;
  for(int i=0; i < strlen(word);i++){
    if (word[i] != c){
      word[j] = word[i];
      j++;
    }
  }
  word[j] = '\0';
}
