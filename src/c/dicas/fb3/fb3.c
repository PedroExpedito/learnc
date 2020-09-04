/*
 * "Bom dia, estou precisando de uma ajuda nesse exercício para faze em
 * linguagem C. Nesse caso, o exercício pede para ler de um arquivo onde contem
 * dois tipos de dados, uma string de nomes e um inteiro. Ao ler esses dados, é
 * para remover todos os nomes repetidos junto com seu valor. Exemplo:
Arquivo de entrada:
João 5
João 5
Maria 6
João 5
Arquivo de saída:
João 5
Maria 6
Eu ja fiz isso:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char pessoa[MAX][MAX];

int countLines(char *path) {
  FILE *arq;
  char c;
  int vezes = 0;
  arq = fopen(path, "r");
  while (fread(&c, sizeof(char), 1, arq)) {
    if (c == '\n') {
      vezes++;
    }
  }
  fclose(arq);
  return vezes;
}

void readData(char *path, int lines) {
  FILE *file;
  file = fopen(path, "r");

  if (file != NULL) {
    for (int i = 0; i < lines; i++) {
      fscanf(file,"%[^\n]\n", *&pessoa[i]);
    }
    fclose(file);
  }
}


int includes(char biVector[MAX][MAX], char *value, int lines) {
  for (int i = 0; i < lines; i++) {
    if ( strcmp(biVector[i], value) == 0){
      return 1;
    }
  }
  return 0;
}

int cmpPessoa(int lines) {
  char newpessoa[MAX][MAX];
  int h = 0;
  for (int i = 0; i < lines; i++) {
    if ( includes(newpessoa, pessoa[i], lines) == 0){
      strcpy(newpessoa[h], pessoa[i]);
      h++;
    }
  }
  for (int i = 0; i < h; i++) {
    strcpy(pessoa[i], newpessoa[i]);
    printf("%s\n", pessoa[i]);
  }
  return h;
}
void write(int lines) {
  FILE *file;
  file = fopen("output.txt", "w");
  for (int i = 0; i < lines; i++) {
    fprintf(file, "%s\n", pessoa[i]);
  }
  fclose(file);
}

void printAA(int lines) {
}

int main(void) {
  char *path = "input.txt";
  int lines = countLines(path);
  readData(path, lines);
  int newLines = cmpPessoa(lines);
  write(newLines);
  printf("%d Lines \n", newLines);

  return 0;
}
