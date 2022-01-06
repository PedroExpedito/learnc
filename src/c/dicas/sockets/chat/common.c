#include "common.h"

#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>

void log_exit(char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

int server_socketaddr_init(const char *proto, const char *portstr,
                           struct sockaddr_storage *storage)
{
  uint16_t port = (uint16_t)atoi(portstr);
  if (port == 0) {
    return -1;
  }
  port = htons(port);
  memset(storage, 0, sizeof(*storage));
  if(strcmp(proto, "v4") == 0) {
    struct sockaddr_in *addr4 = (struct sockaddr_in *)storage;
    addr4->sin_family = AF_INET;
    addr4->sin_port = port;
    addr4->sin_addr.s_addr = INADDR_ANY;
    return 0;
  } else if( strcmp(proto, "v6") == 0) {
    struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *)storage;
    addr6->sin6_family = AF_INET6;
    addr6->sin6_port = port;
    addr6->sin6_addr = in6addr_any;
    return 0;

  } else {
    return -1;
  }
}

int addrparse(const char *addrstr, const char *portstr,
              struct sockaddr_storage *storage) {
  if (addrstr == NULL || portstr == NULL) {
    return -1;
  }

  // mesma coisa de unsigned sort é bom para focar no tamanho
  uint16_t port = (uint16_t)atoi(portstr);

  if (port == 0) {
    return -1;
  }
  // host to network short
  // o numero da porta é sempre big endian
  // host to network ntos
  port = htons(port);

  struct in_addr inaddr4; // 32 bits IP andress

  if (inet_pton(AF_INET, addrstr, &inaddr4)) {
    struct sockaddr_in *addr4 = (struct sockaddr_in *)storage;
    addr4->sin_family = AF_INET;
    addr4->sin_port = port;
    addr4->sin_addr = inaddr4;

    return 0;
  }
  struct in6_addr inaddr6; // 128 bits IPv6 andress

  // presetation to network
  if (inet_pton(AF_INET6, addrstr, &inaddr6)) {
    struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *)storage;
    addr6->sin6_family = AF_INET6;
    addr6->sin6_port = port;
    // addr6->sin6_addr = inaddr6;
    memcpy(&(addr6->sin6_addr), &inaddr6, sizeof(inaddr6));
    return 0;
  }

  return -1;
}

void addrtostr(const struct sockaddr *addr, char *str, size_t strsize) {
  if (str) {
    int version;
    char addrstr[INET6_ADDRSTRLEN + 1] = "";
    uint16_t port;

    if (addr->sa_family == AF_INET) {
      version = 4;
      struct sockaddr_in *addr4 = (struct sockaddr_in *)addr;

      if (!inet_ntop(AF_INET, &(addr4->sin_addr), addrstr,
                     INET6_ADDRSTRLEN + 1)) {
        log_exit("ntop");
      }
      port = ntohs(addr4->sin_port); // network to host short

    } else if (addr->sa_family == AF_INET6) {
      version = 6;
      struct sockaddr_in *addr6 = (struct sockaddr_in *)addr;

      if (!inet_ntop(AF_INET6, &(addr6->sin_addr), addrstr,
                     INET6_ADDRSTRLEN + 1)) {
        log_exit("ntop");
      }
      port = ntohs(addr6->sin_port); // network to host short

    } else {
      log_exit("unkown protocol family.");
    }
    snprintf(str, strsize, "IPv%d %s %hu", version, addrstr, port);
  } else {
    log_exit("str null");
  }
}
