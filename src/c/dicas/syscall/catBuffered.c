#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE 100

int main(int argc, char **argv) {

  if(argc < 1) { return 1; }

  FILE *file = fopen(argv[1], "rb");

  if(file == NULL) {
    return 1;
  }

  char buffer[BUF_SIZE];

  int pos = 0;

  while(buffer[pos] != EOF) {
    if(pos == BUF_SIZE - 1) {
      write(1, buffer, pos);
      pos = 0;
    }
    buffer[pos] = getc(file);
    pos++;
  }
  write(1, buffer, pos);

  return 0;
}
