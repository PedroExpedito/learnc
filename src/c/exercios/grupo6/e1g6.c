/* 1.Fazer um programa em "C" que lê 10 valores e imprime o maior e o menor
valores lidos.
 */
#include <stdio.h>

void arraypost(int *lista,int size);
void sort(int *lista, int size);
void print_v(int *lista, int size);
void print_v_max_min(int *lista,int size);

int main()
{
  int size = 10;
  int lista[size];
  printf("Escreva os valores: \n");
  arraypost(lista,size);
  sort(lista,size);
  print_v(lista,size);
  print_v_max_min(lista,size);

  return 0;
}

void arraypost(int *lista,int size){
  for(unsigned short int contador = 0;contador < size; contador++){
    scanf("%d", &lista[contador]);
    printf("proximo\n");
}
}


void sort(int *lista, int size){
    int contador,memoria, i;

    for (contador = 1; contador < size; contador++){
        for (i = 0; i < size - 1; i++){
            if (lista[i] > lista[i +1]){
            memoria = lista[i];
            lista[i] = lista[i +1];
            lista[i +1] = memoria;
            }
        }
    }
}

void print_v(int *lista,int size){
    int contador;
    printf("Imprimindo valores\n\n");
    for(contador = 0;contador < size; contador++){
        printf("%d\n",lista[contador]);
    }
}

void print_v_max_min(int *lista,int size){
    printf("Maior valor é %d e o menor é %d\n", lista[size -1],lista[0]);
}
