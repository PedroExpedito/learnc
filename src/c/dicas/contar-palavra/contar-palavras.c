#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int count;
} List;

void printList(List *list, int y) {
  for( int i = 0; i < y; i++) {
    printf("Palavra: %s, vezes: %d \n", list[i].name, list[i].count);
  }
}

int genererate(char phrase[10][50], int y) {
  y += 1;
  List list[y];

  for ( int i = 0; i < y; i++ ) {
    list[i].count = 1;
    for ( int j = 0; j < y; j++ ) {
      if ( strcmp(phrase[i], phrase[j]) == 0 && i != j) {
        strcpy(list[i].name, phrase[i]);
        list[i].count += 1;
      }
    }
  }
  printList(list,y);
  return 0;
}



void printBV(char phrase[10][50], int y) {
  for (int i = 0; i <= y; i++) {
    printf("%s\n", phrase[i]);
  }
}

void toLowerCase(char *phrase) {
  for (int i = 0; i < strlen(phrase); i++) {
    phrase[i] = tolower(phrase[i]);
  }
}

char *mostRepetitiveWorld(char *phrase) {
  int words = 0;
  char vector[10][50];

  for (int i = 0; i < strlen(phrase); i++) {
    if (phrase[i] == ' ') {
      words++;
    }
  }
  int i = 0;
  int j = 0;
  int k = 0;

  while (j <= words) {
    while (phrase[i] != ' ' && phrase[i] != '\0') {
      vector[j][i - k] = phrase[i];
      i++;
    }
    vector[j][i - k] = '\0';
    i++;
    j++;
    k = i;
  }

  /* printBV(vector, words); */
  genererate(vector, words);

  return phrase;
}

int main(void) {
  char string[] = "Bom dia como vai você bom dia como";
  toLowerCase(string);
  /* printf("%s\n", string); */
  mostRepetitiveWorld(string);

  return 0;
}
