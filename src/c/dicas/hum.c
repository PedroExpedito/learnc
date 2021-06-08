#include <stdio.h>

void func(int array[]) {
  for (int i = 0; array[i] ; i += 1) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int blah[2];
  func(blah);
}
