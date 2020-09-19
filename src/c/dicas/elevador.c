#include <stdio.h>

int main(void) {
  int peoples[5]; // declaração de um conjunto de 5 valores inteiros
  int maximumWeight = 500; // como não sei o peso maximo que o elevado suporta coloquei como 500
  int sum = 0; // Soma do peso total

  for ( int i = 0; i < 5; i++ ) {
    printf("Peso da pessoa %dº: ",i +1);
    scanf("%d", &peoples[i]);
    getchar(); // limpar o buff de quando tecla entender
    sum += peoples[i];
  }
  if (sum > maximumWeight) {
    puts("Peso excedido!");
  } else {
    puts("Subindo...");
  }
}
