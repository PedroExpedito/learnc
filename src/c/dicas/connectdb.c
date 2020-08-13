#include <stdio.h>
#include <mariadb/mysql.h>

void main(void)
{
      MYSQL conexao;

      mysql_init(&conexao);
      //('localhost','pedro','123','banco_teste');

      if ( mysql_real_connect(&conexao, "localhost", "pedro", "123", "banco_teste", 0, NULL, 0) )
      {
            printf("conectado com sucesso!\n");
            mysql_close(&conexao);
       }
       else
       {
            printf("Falha de conexao\n");
            printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
       }
}
