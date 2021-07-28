#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define FIFO_PATH "/tmp/myfifo"

int main(void) {
  int fd; // file descriptor
  char buf[1024];

  puts("Dijite a mensagem");
  scanf("%1023[^\n]s", buf); 


  mkfifo(FIFO_PATH, 0666);

  fd = open(FIFO_PATH, O_WRONLY);

  write(fd, buf, strlen(buf));

  unlink(FIFO_PATH);

  close(fd);

  return 0;
}
