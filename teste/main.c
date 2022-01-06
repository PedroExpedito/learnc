#include <stdio.h>
#include <stdlib.h>

struct Person {
  char cpf[11];
  char name[100];
};

int main(int argc, char **argv) {
  FILE *file;
  file = fopen("person.data", "w");
  if (file == NULL)
  {
    fprintf(stderr, "\nError opened file\n");
    exit (1);
  }
  struct Person input1 = { "12345678", "Marcos poleto" };
  struct Person input2 = { "12345678", "Fofe poleto" };

  fwrite (&input1, sizeof(struct Person), 1, file);
  fwrite (&input2, sizeof(struct Person), 1, file);

   if(fwrite != 0) {
        printf("contents to file written successfully !\n");
   }
   else {
   printf("error writing file !\n");
   }
 
    // close file
  fclose (file);

}
