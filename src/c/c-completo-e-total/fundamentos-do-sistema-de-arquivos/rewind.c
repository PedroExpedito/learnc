#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char str[80];
  FILE *fp;

  if ((fp = fopen("TEST", "w")) == NULL) {
    printf(" O arquivo não pode ser aberto.\n");
    exit(1);
  }

  printf("dijite uma string:\n");
  scanf("%s", *&str);
  strcat(str, "\n");
  fputs(str, fp);

  rewind(fp);

  fgets(str, 79, fp);
  printf("%s",str);

  exit(0);
}
