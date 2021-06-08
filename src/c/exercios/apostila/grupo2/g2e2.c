/*  Fazer um programa que imprime a tabela ASCII (código decimal, código hexa,
caracter) para os códigos de 0 a 127.
 */
#include <stdio.h>
int main(void)
{
 int a=0;
    printf("IMPRIMINDO TABELA ASCII");
    for(a=1;a<127;a++){
    printf("\n Decimal: %i   Octal: %o Hexadecimal: %x   Caractere: %c ",a,a,a,a);
}
printf("\n");
return 0;
}