/*Fazer uma rotina que recebe um array do tipo double e o número de valores
que devem ser solicitados ao usuário e devolve o array preenchido com os
valores digitados.
*/
#include <stdio.h>
#include <stdlib.h>

void put_array(double *notes,int size);
void print_v(double *notes,int size);

int main()
{   
    int size = 10;
    double notes[size];
    printf("Dijite numeros\n");
    put_array(notes,size);
    print_v(notes,size);


}
void put_array(double *notes,int size)
{
    int i;
    for(i = 0;i < size; i++){
        scanf("%lf", &notes[i]);
        printf("proximo\n");
}
}

void print_v(double *notes,int size){
    int i=0;
    for(i = 0;i < size; i++){
        printf("os valores dijitados são: \n");
        printf("%lf\n", notes[i]);
    }
}
