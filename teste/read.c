#include <stdio.h>
#include <stdlib.h>

struct Person {
  char cpf[11];
  char name[100];
};

int main(int argc, char **argv) {
  FILE *file;
  file = fopen("person.data", "rb");
  if (file == NULL)
  {
    fprintf(stderr, "\nError opened file\n");
    exit (1);
  }

  struct Person input;

  while(fread(&input, sizeof(struct Person), 1, file)) {
    printf("%s %s\n", input.cpf, input.name);
  }

    // close file
  fclose (file);

}
