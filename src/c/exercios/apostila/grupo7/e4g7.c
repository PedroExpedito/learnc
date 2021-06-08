/*4. Fazer um programa em "C" que pregunta o nome, o endereço, o telefone e a
idade de uma pessoa e monta um string com a seguinte frase:
"Seu nome é ..., você tem ... anos, mora na rua ... e seu telefone é ... ."
*/
#include <stdio.h>
int main(){
    
    char nome[80];
    char endereco[80];
    char telefone[20];
    int idade;
    printf("Escreva seu nome: \n");
    scanf("%[^\n]s",&nome);
    setbuf(stdin, NULL); // limpa o buffer do enter
    printf("Escreva seu endereço:");
    scanf("%[^\n]s",&endereco);
    setbuf(stdin, NULL);
    printf("Escreva sua idade: \n");
    scanf("%d",&idade);

    printf("Escreva seu telefone: \n");
    scanf("%s",&telefone);

    printf("Seu nome é %s, você tem %d anos, mora %s e seu telefone é %s\n",nome,idade,endereco,telefone);

    return(0);
}
