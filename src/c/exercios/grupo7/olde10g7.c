/*  Escrever uma função que recebe um string e um caracter como parâmetro e
remove todas as ocorrências do caracter do string.
 */
#include <stdio.h>
#include <string.h>
char rmcaractere(char *palavra,char caractere[0]);
int main(){
  char palavra[100];
  char p[1] = "p";
  printf("Dijite uma palavra: \n");
  scanf("%s",&palavra);
  rmcaractere(palavra, "p");
  printf("%s",palavra);
  printf("precisasaircolocadocomaplavra");
  return 0;
}
char rmcaractere(char *palavra,char caractere[0]){

  char auxpalavra[100] = "\0";
  int i=0,j=0,n=0;
  int soma=0;
  int caracteres = strlen(palavra),auxcactere=caracteres;
  strcpy(auxpalavra,palavra);
  printf("palavra: %s\n",auxpalavra);

  for(i=0;(i + n) < caracteres;i++){ // Eu dijitando a palavra pedro tenho a saida edroo e o for roda 5 vez ao inves de 4 por causa do else
    soma++;
    if(auxpalavra[i] != caractere[0]){
      printf("%c",auxpalavra[i]);
      palavra[j] = auxpalavra[i];
      j++;
    }
    else{
      palavra[i] = palavra[i+ 1];
      n + 1;
      printf("igual\n");
    }
  }
  char auxauxpalavra[100] = "/0";
  for (i=j;i < caracteres;i++){// colocando um espaço no lugar das letras
    palavra[i] = ' ';
  }
  for (i = 0; i < caracteres; i++)
  {
    if (palavra[i] != ' '){
      auxauxpalavra[i] = palavra[i];
    }
    else{
      break;
    }
  }
  strcpy(palavra,auxauxpalavra);
  
  
  printf("vezes que rodei o for: %d\n",soma);
  
  return 0;
}
