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
Servidor aguarda por mensagem do cliente, imprime na tela
e depois envia resposta e finaliza processo
*/
int main(void) {

  // variaveis
  int socket_desc, conexao, c;

  struct sockaddr_in servidor, cliente;

  char *mensagem;

  char resposta[MAX_MSG];
  int tamanho, count;
  // para pegar o IP e porta do cliente
  char *cliente_ip;
  int cliente_port;
  /*********************************************************/
  // Criando um socket
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_desc == -1) {
    printf("Nao foi possivel criar o socket\n");
    return -1;
  }
  int reuso = 1;
  if (setsockopt(socket_desc, SOL_SOCKET, SO_REUSEADDR, (const char *)&reuso,
                 sizeof(reuso)) < 0) {
    perror("Não foi possível reusar endereço");
    return -1;
  }
#ifdef SO_REUSEPORT
  if (setsockopt(socket_desc, SOL_SOCKET, SO_REUSEPORT, (const char *)&reuso,
                 sizeof(reuso)) < 0) {
    perror("Não foi possível reusar porta");
    return -1;
  }
#endif
  // Preparando a struct do socket
  servidor.sin_family = AF_INET;
  servidor.sin_addr.s_addr = INADDR_ANY; // Obtem IP do S.O.
  servidor.sin_port = htons(1234);
  // Associando o socket a porta e endereco
  if (bind(socket_desc, (struct sockaddr *)&servidor, sizeof(servidor)) < 0) {
    perror("Erro ao fazer bind\n");
    return -1;
  }
  puts("Bind efetuado com sucesso\n");
  // Ouvindo por conexoes
  listen(socket_desc, 3);
  /*********************************************************/
  // Aceitando e tratando conexoes
  puts("Aguardando por conexoes...");
  c = sizeof(struct sockaddr_in);
  while (1) {
    conexao = accept(socket_desc, (struct sockaddr *)&cliente, (socklen_t *)&c);
    if (conexao < 0) {
      perror("Erro ao receber conexao\n");
      return -1;
    }
    /*********************************************************/
    /*********comunicao entre cliente/servidor****************/
    // pegando IP e porta do cliente
    cliente_ip = inet_ntoa(cliente.sin_addr);
    cliente_port = ntohs(cliente.sin_port);
    printf("cliente conectou\nIP:PORTA -> %s:%d\n", cliente_ip, cliente_port);
    // lendo dados enviados pelo cliente
    if ((tamanho = read(conexao, resposta, MAX_MSG)) < 0) {
      perror("Erro ao receber dados do cliente: ");
      return -1;
    }
    // Coloca terminador de string
    resposta[tamanho] = '\0';
    printf("O cliente falou: %s\n", resposta);
    // Enviando resposta para o cliente
    mensagem = "Ola cliente, tudo bem?";
    write(conexao, mensagem, strlen(mensagem));
    /*********************************************************/
  }

  close(socket_desc);
  shutdown(socket_desc, 2);

  printf("Servidor finalizado...\n");
  return 0;
}
