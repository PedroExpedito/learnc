/* Calcular media moda e mediana */
#include<stdio.h>
void impriarray(float *array,int tam);
void bublleshot(float *array,int tam);
void mediana(float *array,int tam);
void media(float *array,int tam);
void moda(float *array,int tam);
int main(void){
    unsigned short int tam = 6;
    float array[6]={5,1,4,3,2,6};
    bublleshot(array,tam);
    impriarray(array,tam);
    mediana(array,tam);
    media(array,tam);
    moda(array,tam);
}
void bublleshot(float *array,int tam){
    int aux=0;
    for (unsigned int x = 1; x < tam; x++) {
        for (unsigned int i = 0; i < tam - 1; i++) {
            if (array[i] > array[i + 1]) {
                aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
     }
   }
 }
}
void impriarray(float *array,int tam){
    for(unsigned int i=0;i<tam;i++){
        printf("%f\n",array[i]);
    }
}
void mediana(float *array,int tam){
    unsigned short int resto = tam % 2;
    if(resto == 0){
        float mediana = ((array[tam/2] + array[((tam/2)-1)]) / 2);
        printf("mediana do vetor par é%f",mediana);
    }
    else{
    printf("a mediana do vetor impar é %f",array[((tam+1)/2)]);
    }

}
void media(float *array,int tam){
    int soma=0;
    for(unsigned short int i=0;i < tam;i++){
        soma += array[i];
    }
    printf("\nMedia é %f\n",soma/tam);
}
void moda(float *array,int tam){
    for(unsigned short int i = 0;i<tam;i++){
        for(unsigned short int j=0;j<tam;j++){
            if(array[i] == array[j]){
                printf("true");
            }
        }
    }
}