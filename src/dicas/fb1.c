/*Ola a todos, estou com uma certa dificuldade de criar um laço nesse switch
case, quando eu rodo ele fica infinito. Eu preciso que o usuario finalize o
programa, poderiam me ajudar?
https://github.com/lokaut/teste/blob/master/.gitignore*/
#include <stdio.h>
#include <stdlib.h>

// maior erro é foi pensar em dinheiro como REAL e não como centavo, ao inves de pensar que
// R$: 3,23 são 323 centavos você pessou que são 3 reais e 23 centavos é um erro, por causa do ponto
// flutuante da uma olhada em qualquer linguagem de programação faz 0.3 + 0.3 + 0.3 o rezultado não é 0.9 e sim 0.899999......
// isso parece um erro pequeno porém quando é grandes quantidades de dinheiro pode chegar em uma taxa de erro de 6% ou mais
// trabalha com int quando é dinheiro, float é para coisas espeficicas como algum tipos de calculos de graficos etc, um pouco disso é culpa dos
// professores que para ensinar uso do float usam dinheiro como exemplo...

int menu(int preco){

  int codigo;
  int aux = preco;

    printf("=== ola, digite qual código do produto que você gostaria de comprar===\n\n");
    printf("                                                 \n\nValor a pagar R$%.2f\n\n",(float)preco/100);// a conversão em C é estranha
    printf("           cachorro quente código 100, preço 1.20\n");
    printf("           Bauru simples   código 101, preço 1.30\n");
    printf("           bauru com ovo,  código 102, preço 1.50\n ");
    printf("           hamburguer,     código 103, preço 1.20\n");
    printf("           cheeseburguer.  código 104, preço 1.30\n");
    printf("\nDijite código 9 para SAIR\n");

    scanf("%d", &codigo);

    switch (codigo) {
    case 100:
      printf("você escolheu cachorro preço com preço de 1.20\n");
      preco = 120;
      break;

    case 101:
      printf("você escolheu escolheu bauru simples com o preço de 1.30\n");
      preco = 130;
      break;

    case 102:
      printf("você escolheu um bauru com ovo com o preço de 1.50\n");
      preco = 150;
      break;

    case 103:
      printf("você escolheu hamburguer com o preço 1.20");
      preco = 120;
      break;

    case 104:
      printf("você escolheu cheeseburguer preço 1.30");
      preco = 130;
      break;
    case 9:
      exit(0);
    default:
      printf("valor invalido\n");
      break;
    }
    system("clear"); // em ambiente Unix limpa a tela
    preco += aux;
    return preco;
  }


int main() {
  int preco=0;
  while(1){
  preco = menu(preco);
  }
  return 0;
}
