#include <stdio.h>

int main(void) {
  long double denominador = 27; // pulando o primeiro
  long double numerador = 2;// pulando o primeiro
  long double resultado = 0;

  while(denominador > 1) {
    resultado += numerador/denominador;
    denominador -= 2;
    numerador *= 2;
  }

  printf("Resultado: %Lf, Denominador Final: %Lf, Numerador final: %Lf.\n",resultado,denominador,numerador);

  // você pode passar isso para fração dividindo

}
