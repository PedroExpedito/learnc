#include<stdio.h>
#include <stdlib.h>

// exemplo de foreach para array de tipos primitivos
// Não funciona com array que é alocado em tempo de execução
// e ainda é mais lento comparado com passar o tamanho por paramentro
// para alguma função.


#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)

int main(void) {
  float values[] = { 1.5, 3.3, 4.8};


  foreach(float *v, values) {
    printf("valor: %f\n", *v);
  }

  return 0;
}
