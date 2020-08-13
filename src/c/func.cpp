#include <stdio.h>

void print(int x) {
  printf("%i", x);
}
void print(int x, int y) {
  printf("%i %i", x, y);
}

int main(void) {
  print(1);
}
