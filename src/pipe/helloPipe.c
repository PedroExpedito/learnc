/*
 * [pipe1.c]
 * Programa que usa pipes para se comunicar
 * com um processo filho.
 *
 * [Autor]
 * Marcos Paulo Ferreira (daemonio)
 * undefinido gmail com
 * https://daemoniolabs.wordpress.com
 *
 * [Uso]
 * $ gcc -o pipe1 pipe1.c
 * $ ./pipe1
 *
 * Versão 1.0, by daemonio @ Sat Aug 11 16:55:56 BRT 2012
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h> /* for pipe() */

#define BUFFER 256

int main(void) {
  char msg[BUFFER];
  int fd[2];
  int pid;

  /* Cria um pipe. */
  if (pipe(fd) < 0) {
    perror("pipe");
    return -1;
  }

  /* Cria processo filho. */
  pid = fork();

  if (pid == -1) {
    perror("fork");
    return -1;
  }

  /* Processo filho. */
  if (pid) {
    char *hello = "Hello World!";

    /* Operação obrigatória: fechar o descritor
     * desnecessário. */
    close(fd[0]);

    /* Escreve a mensagem no pipe. */
    write(fd[1], hello, strlen(hello) + 1);

    close(fd[1]);
  } else { /* Processo pai. */
    /* Operação obrigatória: fechar o descritor
     * desnecessário. */
    close(fd[1]);

    /* Lê a mensagem do pipe. */
    read(fd[0], msg, sizeof msg);

    printf("Mensagem recebida: %s\n", msg);

    close(fd[0]);
  }

  return 0;
}
/* EOF */
