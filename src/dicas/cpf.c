#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
    char cpf[12];
    int converter;
    int soma = 0;
    int result = 0;
    printf("Dijite o CPF: \n");
    scanf("%s",&cpf);
    for(int i=0;i < 9;i++){
        converter = cpf[i] - '0';
        printf("%d\n",converter);
        converter = converter * (10 - i);
        //printf("%d\n",converter);
        soma += converter;
    }
    result = (soma*10);
    result = result % 11;
    if (result <= 1){
        printf("J é 0");
    }
    else{
        printf("J é 1");
    }
}