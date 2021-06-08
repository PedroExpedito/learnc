/*4. Exercício: fazer um programa em "C" que solicita o total gasto pelo cliente de
uma loja, imprime as opções de pagamento, solicita a opção desejada e
imprime o valor total das prestações (se houverem).
1) Opção: a vista com 10% de desconto
2) Opção: em duas vezes (preço da etiqueta)
3) Opção: de 3 até 10 vezes com 3% de juros ao mês (somente para compras
acima de R$ 100,00).
*/
// exercio 3 
// em varias func 
#include <stdio.h>

int imprima();
int opcao1();
int opcao2();
int opcao3();
int main()
{
imprima();
}
int imprima(void){
  int dijitado;
  printf("Dijite: 1 para a vista com 10%% de desconto\n");
  printf("Dijite: 2 para em duas vezes (preço da etiqueta)\n");
  printf("Dijite: 3 para parcelas de até 10 vezes com 3%% de juros ao mês (somente para compras acima de R$ 100,00)\n");
  scanf("%d",&dijitado);
  switch ( dijitado )
  {
  case 1:
    opcao1();
    break;
  case 2:
    opcao2();
    break;
  case 3:
    opcao3();
    break;
  
  default:
    break;
  }

}
int opcao1(void){
  float gasto;
  printf("Insira o gasto do cliente: \n");
  scanf("%f",&gasto);
  printf("Valor a pagar R$:%.2f\n",gasto * 0.9);
}
int opcao2(void){
  float gasto;
  printf("Insira o gasto do cliente: \n");
  scanf("%f",&gasto);
  printf("Duas parcelas de R$:%.2f\n",gasto/2);
}
int opcao3(void){
  float gasto,total;
  int parcelas;
  printf("Insira o gasto do cliente: \n");
  scanf("%f",&gasto);
  if(gasto >= 100){
    printf("Quantas parcelas ?\n");
    scanf("%d",&parcelas);
    total = gasto / parcelas;
    total = total + (total * 0.03);
    printf("em %d parcelas cada uma fica R$:%.2f\n", parcelas,total);
  }
  else{
    printf("o valor da compra do cliente é inferior a 100 reais use outra opção!\n");
    imprima();
  }
}
