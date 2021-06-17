#pragma once
#include <arpa/inet.h>
#include <stdint.h>
#include <sys/socket.h>

void log_exit(char *msg);

int server_socketaddr_init(const char *proto, const char *portstr,
                           struct sockaddr_storage *storage);

int addrparse(const char *addrstr, const char *portstr,
              struct sockaddr_storage *storage);

void addrtostr(const struct sockaddr *addr, char *str, size_t strsize);
