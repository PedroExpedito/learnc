#include <stdio.h>


int quad(int x) {
  return x * x;
}

typedef struct {
  int (*Pquad)(int);
} Math;

void MathContructor(Math *math) {
  math->Pquad = quad;
}

int main(void) {
  Math math;
  MathContructor(&math);
  printf("%d\n", math.Pquad(2));
  return 0;
}
