/*9. Fazer um programa em "C" que leia nomes de pessoas compostos por um pré-
nome e um sobrenome separados por um espaço em branco e imprima:
- A lista de nomes em ordem alfabética do pré-nome;
- A lista de nomes em ordem alfabética de sobrenomes;
- O número médio de letras por nome. 
Obs:
•
 a quantidade de nomes lidos deve ser menor ou igual a 20;
•
 uma seqüência de nomes é encerrada pela palavra "FIM" ou quando for lido o
20 nome.
*/

#include <stdio.h>
#include <string.h>
#define TAM  20
int main(){

  float media=0,soma=0;
  int i=0,j=0,dijitados=0;
  char nomes[TAM][20],aux[20];
  char sobrenomes[TAM][40],saux[40];

  printf("Coloque a Lista de Nomes; Dijite FIM para sair.\n");

  for(i=0;i < TAM;i++){
    char tmpnomes[TAM][20];
    char tmpsobrenomes[TAM][40];
    printf("Nome %d: ",i+1);
    scanf("%s%[^\n]s",&tmpnomes[i],&tmpsobrenomes[i]);
    setbuf(stdin, NULL);
    if(strcmp(tmpnomes[i], "FIM") != 0)
    {
      dijitados++;
      strcpy(nomes[i],tmpnomes[i]);
      strcpy(sobrenomes[i],tmpsobrenomes[i]);
    }
    else{
      break;
    }
  }

//organizar array em ordem alfabetica dos pre-nomes
  for (i = 1; i < dijitados; i++) {
   for (j = 1; j < dijitados; j++) {
      if (strcmp(nomes[j - 1], nomes[j]) > 0) {
         strcpy(aux, nomes[j - 1]);
         strcpy(nomes[j - 1], nomes[j]);
         strcpy(nomes[j], aux);
      }
   }
}
//organizar array dos sobrenomes
for (i = 1; i < dijitados; i++) {
   for (j = 1; j < dijitados; j++) {
      if (strcmp(sobrenomes[j - 1], sobrenomes[j]) > 0) {
         strcpy(aux, sobrenomes[j - 1]);
         strcpy(sobrenomes[j - 1], sobrenomes[j]);
         strcpy(sobrenomes[j], aux);
      }
   }
}

//imprimir nomes
printf("\nA lista de nomes em ordem alfabética do pré-nome: \n");
for (i = 0; i < dijitados; i++){
   printf("\n%s", nomes[i]);
}
//imprimir sobrenomes
printf("\nA lista de nomes em ordem alfabética de sobrenomes: \n");
for (i = 0; i < dijitados; i++){
  printf("%s\n", sobrenomes[i]);
}
for (i = 0; i < dijitados; i++){
    soma += strlen(nomes[i]);
  }
  media = soma / dijitados;
printf("Numero medio de letras por nome: %.2f \n",media);
}

