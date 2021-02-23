// Objeto desse programar é receber uma um texto (string) e uma key (string)
// e com isso tanto cryptor quanto descryptografar

// melhorias
//
// separar em pequenas funções
// tratar erros
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long SIZE;

void cryptoToFile(long *text) {

  FILE *file = fopen("data", "w");
  if ( file == NULL || ferror(file) ) {
    perror("data.crypt");
    exit(1);
  }

  fprintf(file, "%lu\n", SIZE);

  for ( long i = 0; i < SIZE; i++ ) {
    fprintf(file,"%lu ",text[i]);
  }
}

// arquivo para string
void charToFile(char *text) {
  FILE *file = fopen("data.crypt", "w");
  if ( file == NULL || ferror(file) ) {
    perror("data.crypt");
    exit(1);
  }
  if(fputs(text, file) == EOF ){;
    fprintf(stderr, "Error na gravação");
    fclose(file);
    exit(1);
  }
}

// le um arquivo cryptografo e retorna a string
// para descrypt

long * fileToLongArray(char *path) {

  FILE *file = fopen(path, "r");

  if( file == NULL || ferror(file)) {
    perror(path);
    puts("Erro ao abrir arquivo");
    exit(1);
  }
  fscanf(file, "%ld\n", &SIZE);

  long *readFile = malloc(sizeof(long)*SIZE);

  for ( int i = 0; i < SIZE ; i++) {
      fscanf(file,"%ld ", &readFile[i]);
  }
  fclose(file);

  return readFile;
}

// le um arquivo para ser encryptado e retorna um
// array de char

char * fileToChar(char *path) {

  FILE *file = fopen(path, "r");

  long ISize;
  char *buffer;

  fseek(file, 0L, SEEK_END);
  ISize = ftell( file );
  rewind( file );

  buffer = calloc(1,ISize+1);

  if( !buffer ) {
    fclose(file);
    fprintf(stderr, "memory alloc fails");
    exit(1);
  }

if (1 != fread(buffer, ISize, 1, file)) {
  fclose(file);
  free(buffer);
  fprintf(stderr, "entire read fails");
  exit(1);
}

return buffer;

}

// descriptografa string com a key

char *decrypt_text(long *text, char* key) {

  char *result = malloc(sizeof(char) * SIZE + 1);

  for( unsigned long i = 0; i <  SIZE; i++) {
    for( unsigned long j = 0; j < strlen(key); j++) {
      result[i] = text[i] / key[j];
    }
  }
  return result;
}

// cryptografa

long *crypt_text(char *text, char* key) {
  long sizeKey = strlen(key);
  long sizeText = strlen(text);

  long *result = malloc(sizeof(unsigned long) * sizeText);

  for( unsigned long i = 0; i < sizeText; i++) {
    for( unsigned long j = 0; j < sizeKey; j++) {
      result[i] = text[i] * key[j];
    }
  }
  return result;
}

int main(int argc, char **argv) {

  char key[200];

  if ( argv[1] != NULL) {

    if(strcmp(argv[1],"-d") == 0 && argv[2] != NULL) {

      puts("Dijite a senha:");
      scanf("%s", key);

      long *forDescrypt = fileToLongArray(argv[2]);
      char *descrypt = decrypt_text(forDescrypt, key);
      puts(descrypt);
      free(forDescrypt);

    } else if(strcmp(argv[1],"-c") == 0 && argv[2] != NULL) {
      puts("Dijite a senha para criptografar:");
      scanf("%s", key);

      char *forCrypt = fileToChar(argv[2]);
      SIZE = strlen(forCrypt);

      long *crypt = crypt_text(forCrypt, key);
      cryptoToFile(crypt);
      free(forCrypt);
      free(crypt);
    }
  } else {
  exit(0);
  }




  /* free(result); */

  return 0;
}
