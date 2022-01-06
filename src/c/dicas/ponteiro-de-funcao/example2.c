#include <stdio.h>

void hello() {
  puts("hello");
}

void hellos(int vezes, void (*foo)()) {
  for ( int i = 0; i < vezes; i++) {
    foo();
  }
}

int main(void) {
  hellos(4, hello);

  return 0;
}
