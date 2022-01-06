#include "common.h"

#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

static volatile bool running = true;

void exit_program() { exit(EXIT_FAILURE); }
void runningHandler() {
  running = false;
  puts("Closing");
  exit_program();
}

void usage(char **argv) {
  printf("usage: %s <v4|v6> <server port>", argv[0]);
  printf("Example: %s v4 5111\n", argv[1]);
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
  signal(SIGINT, runningHandler);
  if (argc < 3) {
    usage(argv);
  }

  struct sockaddr_storage storage;
  if (0 != server_socketaddr_init(argv[1], argv[2], &storage)) {
    usage(argv);
  }
  int s;
  s = socket(storage.ss_family, SOCK_STREAM, 0);

  // setando opção para socket
  // reuseadd
  int enable = 1;
  if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) != 0) {
    log_exit("setsockopt(SO_REUSEADDR) failed");
  }

  if (s == -1) {
    log_exit("socket");
  }

  struct sockaddr *addr = (struct sockaddr *)(&storage);
  if (0 != bind(s, addr, sizeof(storage))) {
    log_exit("bind");
  }
  if (0 != listen(s, 10)) {
    log_exit("listen");
  }
  char addrstr[BUFFER_SIZE];
  addrtostr(addr, addrstr, BUFFER_SIZE);
  printf("bound to %s\n", addrstr);

  while (1) {
    struct sockaddr_storage cstorage;
    struct sockaddr *caddr = (struct sockaddr *)(&cstorage);

    int c = sizeof(struct sockaddr_storage);

    // aceitando conexões
    // a funcao accept funciona como um while
    int csock = accept(s, caddr, (socklen_t *)&c);
    if (csock == -1) {
      log_exit("accept");
    }

    char caddrstr[BUFFER_SIZE];
    addrtostr(caddr, caddrstr, BUFFER_SIZE);
    printf("[log] connection from %s\n", caddrstr);

    char buf[BUFFER_SIZE];

    // recebendo dados

    size_t count = recv(csock, buf, BUFFER_SIZE, 0);
    // imprimindo dados
    printf("[msg] '%s', %d bytes: %s\n", caddrstr, (int)count, buf);
    // zerando o buff
    memset(buf, 0, BUFFER_SIZE);

    // enviando resposta

    sprintf(buf, "remove endpoint: %.1000s\n", caddrstr);

    count = send(csock, buf, strlen(buf) + 1, 0);

    // melhorar arrumar isso
    if (count != strlen(buf) + 1) {
      log_exit("send");
    }
  }

  close(s);
  shutdown(s, 2);

  return 0;
}
