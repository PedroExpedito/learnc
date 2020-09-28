#ifndef algorithm_h/* Include guard */
#define algorithm_h

//*****************************************************//
//*********************- ORDENAÇÂO -*******************//
//*****************************************************//


// Normalmente á estretegia é simples dividir para consquitar
void mergeSort(int vetor[], int comeco, int fim);

// imprimir um vetor de vetor
int printv(int size, int *vector);

// retorna o quadrado
int quad(int n);

// algoritimo bubbleSort é bem lento
int bubbleSort(int size, int *vector);

// algoritimo de ordenação por insersão
int insertion_sort(int size, int *vector);


#endif
