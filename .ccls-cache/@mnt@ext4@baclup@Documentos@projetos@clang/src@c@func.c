#include <stdio.h>

void print(int x) {
  printf("%i", x);
}
void print(char *x) {
  printf("%i", *x);
}

int main(void) {
  print(10);
}
