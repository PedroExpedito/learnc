#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char name[100];
  int i = -1;
  scanf("%s", *&name);

  while(name[i-1] != '\n') {
    name[i] = getchar();
    i++;
  }
  puts(name);
}
