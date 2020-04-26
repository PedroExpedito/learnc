/*Fazer um programa em "C" que lê um conjunto de 10 valores inteiros e verifica
se algum dos valores é igual a média dos mesmos.
*/
#include <stdio.h>
#include <stdlib.h>
//funcs
void put_array(int *notas,int tamanho);
int calc_media(int sum,int tamanho);
int is_val_media(int *notas,int media,int tamanho);
int sum_v(int *notas,int tamanho);
//fim
int main()
{   
    int tamanho = 10,media=0,existe=0,sum=0;
    int notas[tamanho];
    printf("Dijite numeros\n");
    put_array(notas,tamanho);
    sum = sum_v(notas,tamanho);
    media = calc_media(sum,tamanho);
    is_val_media(notas,media,tamanho);
}
void put_array(int *notas,int tamanho)
{
    int i;
    for(i = 0;i < tamanho; i++){
        scanf("%d", &notas[i]);
        printf("proximo\n");
    }
}

int calc_media(int sum,int tamanho){
    return sum/tamanho;
}

int is_val_media(int *notas,int media,int tamanho){
    for(unsigned short int i =0; i < tamanho; i++){
        if(media == notas[i]){
            printf("Existe sim é o valor %d\n",notas[i]);
            return 1;
        }
        else{printf("não existe\n");return 0;}
    }
    return 0;
}
int sum_v(int *notas,int tamanho){
    int i=0;
    int sum=0;
    for (i=0; i < tamanho; i++){
        sum += notas[i];// aqui fazendo conta errada
    }
    return sum;
}
