#include <stdio.h>
#include "algorithm.h"
#include <math.h>
#include <stdlib.h>

void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }

    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}
/* Insersion sort  */
int insertionSort(int size, int *vector){
  int aux;
  for ( int i = 1; i < size; i++ ) {
    int j = i - 1;
    int aux = vector[i];
    while(j >= 0 && aux < vector[j]) {
      vector[j+1] = vector[j];
      j--;
    }
    vector[j+1] = aux;
  }
  return 0;
}

/* imprimir vetores */
int printv(int size, int *value) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d", value[i]);
  }
  printf("\n");
  return i;
}

/* quadrado de numero  */
int quad(int n) {
  printf("%d",n);
  return n*n;
}
/* ordenar vetor em ordem crescente*/
int sort(int size, int *vector) {
  int aux;
  for (int j = 0; j < size; j++) {
    for (int i = 0; i < size; i++) {
      if (vector[i+1] < vector[i]) {
        aux = vector[i+1];
        vector[i+1] = vector[i];
        vector[i] = aux;
      }
    }
  }
  return 0;
}
