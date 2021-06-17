#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_MSG 1024
/*
        Experimento 01

        Cliente envia mensagem ao servidor e imprime resposta
        recebida do Servidor

        Cliente conhece o endereco IPv4 do servidor
*/
int main(int argc, char *argv[]) {
  // variaveis
  int ativo = 1;
  int socket_desc;
  struct sockaddr_in servidor;
  char mensagem[MAX_MSG];
  char resposta_servidor[MAX_MSG];
  int tamanho;

  /*****************************************/
  /* Criando um socket */
  // AF_INET = ARPA INTERNET PROTOCOLS
  // SOCK_STREAM = orientado a conexao
  // 0 = protocolo padrao para o tipo escolhido -- TCP
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);

  /* Informacoes para conectar no servidor */
  // IP do servidor
  // familia ARPANET
  // Porta - hton = host to network short (2bytes)
  servidor.sin_addr.s_addr = inet_addr("127.0.0.1");
  servidor.sin_family = AF_INET;
  servidor.sin_port = htons(1234);

  // Conectando no servidor remoto
  if (connect(socket_desc, (struct sockaddr *)&servidor, sizeof(servidor)) <
      0) {
    printf("Nao foi possivel conectar\n");
    return -1;
  }
  printf("Conectado no servidor\n");
  if (connect(socket_desc, (struct sockaddr *)&servidor, sizeof(servidor)) <
      0) {
    printf("Nao foi possivel conectar\n");
    return -1;
  /*****************************************/

  /*******COMUNICAO - TROCA DE MENSAGENS **************/
  // Protocolo definido para essa aplicacao
  // 1 - Cliente conecta
  // 2 - Cliente envia mensagem
  // 3 - Servidor envia resposta

  // Enviando uma mensagem
  }
  while (ativo) {

    puts("Dijite a mensagem:");
    scanf("%s", mensagem);
    if (send(socket_desc, mensagem, strlen(mensagem), 0) < 0) {
      printf("Erro ao enviar mensagem\n");
      ativo = 0;
    } else {
      puts("Dados enviados\n");
    }
  }
  /*****************************************/
  close(socket_desc); // fechando o socket
  printf("Cliente finalizado com sucesso!\n");
  return 0;
}
