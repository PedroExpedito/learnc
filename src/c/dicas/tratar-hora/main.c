// Não entendi direito sua dúvida

// Se tu não quer deixar essa "99:99" entrada passar ou seja uma hora errada é simples

#include <stdio.h>
#include <string.h>

// 12 horas
// jamais a primeira casa pode ser maior que 1
// a segunda casa não precisa verificar ela pode ir de 0 a 9
// se a primeira casa for 1 a segunda casa não pode ser maior que 2

int main(void) {
  char num[] = "11";
  int numero;
  sprintf(num, "%d", numero);
  printf("Imprimido %d", numero);
  return 0;
}
