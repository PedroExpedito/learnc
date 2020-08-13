#include <stdio.h>

int primo(int n) {
  if (n <= 1) {
    return 0;
  }
  if (n % 2 == 0 && n != 2) {
    return 0;
  }
  if (n % 3 == 0 && n != 3) {
    return 0;
  }
  if (n % 4 == 0) {
    return 0;
  }
  if (n % 5 == 0 && n != 5) {
    return 0;
  }
  if (n % 7 == 0 && n != 7) {
    return 0;
  }

  return 1;
}

int teste(int n){
  for(int i=0; i <= n; i++){
    printf("%d é primo ?: %d\n", i, primo(i));
  }
  return 0;
}

int main(void) {
  teste(100);
  return 0;
}
