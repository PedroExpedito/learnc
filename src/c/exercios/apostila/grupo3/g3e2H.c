/* Faca um programa em "C" que le dois números e utiliza uma função chamada
"soma" e outra chamada "subtracao" para imprimir a soma e a diferenca entre
os dois números. Ambas funções devem receber dois inteiros como parâmetro
e retornar um inteiro como resultado. O programa deve ter duas versões para
os protótipos das funções selecionáveis através da definição das constantes:
"KR" (Kernighan e Ritchie) e "ANSI" (padrão ANSI).
 */
#include <stdio.h>
int subtracao(int x,int y);
int soma(int x,int y);
int main(void){

}
int subtracao(int x,int y){
    return x-y;
}
int soma(int x,int y){
    return x+y;
}