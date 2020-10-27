#include <stdio.h>
#include <stdarg.h>

int spread(const char* name, ...) {
  va_list arguments;
  va_start(arguments, name);
  int soma = va_arg(arguments,int);
  printf("%d", soma);
  va_end(arguments);
  return 0;
};
int main(void){
  spread("oi", 1,2);
};
