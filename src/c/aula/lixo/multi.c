#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main( int argc, char *argv[ ] )
{
  unsigned short int valora=0;
  unsigned long long int resultado;
  //atoi converte de alfanumérico para inteiro
  valora = atoi(argv[1]);
  resultado = valora;
  if (valora < 21){

  for(int i=valora;i > 1;i--){
    resultado = (resultado * (i-1));

  }
  printf("%lld\n",resultado);
  }
  else{printf("Não é possivel calcular fatorial maior que 20\n");
  return 0;
  }
}
