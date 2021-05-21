#include<stdio.h>

// exemplo de foreach para array de tipos primitivos

#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)

int main(void) {
  float values[] = { 1, 2, 3 };

  foreach(float *v, values) {
    printf("valor: %f\n", *v);
  }

}
