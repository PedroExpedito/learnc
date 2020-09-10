#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define conve 0.62137
#define ERROR(msg, exitCode) fprintf(stderr, "%s\n", msg); exit(exitCode)
#define print(x) printf("%d", x);

long double ml2km(long double ml) {
  return ml / conve;
}

long charmulti(char *cha, char *multi) {
  return 0;
}

char *stdin2str() {
  char *result;
  unsigned long long int size = sizeof(stdin) + 1;
  if ( size > ULONG_MAX) {
    ERROR("Valor Muito alto", 1);
  }
  result = malloc(size);
  fgets(result,sizeof(stdin) + 1, stdin);
  return result;
}
int main(int argc, char *argv[]) {
  printf("String é: %s \n", stdin2str());
  return 0;
}
