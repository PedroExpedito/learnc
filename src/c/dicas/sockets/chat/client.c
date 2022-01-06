#include "common.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>


#define BUFFER_SIZE 1024

void usage() {
  printf("usage: <server IP>:<server port>");
  printf("Example: 127.0.0.1:5111");
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
  if ( argc < 3){
    usage();
  }

  struct sockaddr_storage storage;
  if( 0 != addrparse(argv[1], argv[2], &storage)) {
    usage();
  }

  int s;
  s = socket(storage.ss_family, SOCK_STREAM, 0);

  if( s == -1) {
    log_exit("socket");
  }

  // funciona como uma uma interface/super classe
  struct sockaddr *addr = (struct sockaddr *)(&storage);

  if (0 != connect(s, addr, sizeof(storage))) {
    log_exit("connect");
  }

  char addr_str[BUFFER_SIZE];

  addrtostr(addr, addr_str, BUFFER_SIZE);

  printf("connect to %s\n", addr_str);

  char buffer[BUFFER_SIZE];
  memset(buffer, 0 , BUFFER_SIZE);
  printf("Dijite a mensagem:\n ");

  fgets(buffer, BUFFER_SIZE-1, stdin);

  long strSize =  strlen(buffer) + 1;
  send(s, "pedro", 5, 0);
  send(s, "expedito", 8, 0);
  send(s, "de", 2, 0);
  int count = send(s, buffer, strSize, 0);
  if(count != strSize) {
    log_exit("send");
  }

  memset(buffer, 0 , BUFFER_SIZE);

  /* unsigned total = 0; */
  /* while(1) { */
  /*   count = recv(s, buffer + total , BUFFER_SIZE - total, 0); */
  /*   if(count == 0) { */
  /*     break; */
  /*   } */
  /*   total += count; */
  /* } */

  /* printf("received %d bytes\n", total); */
  close(s);

  return 0;
}
