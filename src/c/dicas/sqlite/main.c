#include <sqlite3.h>
#include <stdlib.h>
#include <stdio.h>

static int print_professor_sql(void *unused, int count, char **data, char **columns)
{
    int idx;

    for (idx = 0; idx < count; idx++) {
        printf("coluna \"%s\" valor: %s\n", columns[idx], data[idx]);
    }


    return 0;
}
void log_exit(const char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

char errBuffer[500];

int main(void) {
  char *path = "./banco.sqlite";
  char *err = NULL;
  sqlite3 *db;

  if( sqlite3_open(path, &db)) {
    log_exit("error to open db");
  }


  sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS professor( nome VARCHAR(50));", NULL, NULL, &err);

  puts("Dijite o nome do professor");
  char name[100];
  scanf("%[^\n]s", name);
  char sql[500];

  snprintf(sql,500, "INSERT INTO professor( nome ) VALUES ('%s')",name);

  sqlite3_exec(db, sql , NULL, NULL, &err);

  sqlite3_exec(db, "select * from professor;", print_professor_sql, NULL, &err);

  if(err) {
    snprintf(errBuffer, 500, "Erro ao criar a tabela: %s", err);
    sqlite3_close(db);
    log_exit(errBuffer);
  }

 // free(err);
  sqlite3_close(db);

}
