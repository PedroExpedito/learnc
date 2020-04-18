/*3. Fazer uma rotina que recebe como parâmetro um string contendo um número e
um inteiro indicanndo a base na qual o número está expresso, retornando o seu
valor em decimal
Ex: conv2dec("345", 8) => 229*/
 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int conv2dec(char *number,int type);
int main(){
  int a = conv2dec("1101",2);
  printf("%d\n",a);
}
int conv2dec(char *number,int type){
  {
    
    int decimal = 0;
    int i = 0;
    int valor = atoi(number);
    while (valor != 0)
    {
        decimal =  decimal +(valor % 10)* pow(type, i++);
        valor = valor / 10;
    }
    return decimal;
}
}
