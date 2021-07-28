#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void) {
  int fd;
  char buf[1024];

  fd = open("/tmp/myfifo", O_RDONLY);

  read(fd, buf, sizeof(buf)); 
  printf("message: %s\n", buf);
  close(fd);

}
