#include<json-c/json.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#define ERROR(i, msg) printf("%s\n", msg); exit(i)

int main(int argc, char **argv) {

  if(argc < 2) {
    ERROR(EXIT_FAILURE, "Passe o arquivo como argumento");
  }

  FILE *data;

  data = fopen(argv[1], "r");

  if (data == NULL) {
    ERROR(1, "File Not Found");
  }

  struct json_object *parsed_json;

  struct json_object *name;
  struct json_object *surname;

  //  tamanho do buffer
  fseek(data, 0, SEEK_END);

  //Não precisa de sizeof(char) em todas as arquituturas é um bit
  unsigned long long int bufferSize = ftell(data);
  char *buffer = malloc(bufferSize);

  // voltar ao inicio
  fseek(data, 0, SEEK_SET);

  // passar para o buffer
  fread(buffer, bufferSize, 1, data);
  // fechando arquivo
  fclose(data);

  parsed_json = json_tokener_parse(buffer);

  json_object_object_get_ex(parsed_json, "name", &name);
  json_object_object_get_ex(parsed_json, "surname", &surname);

  printf("Seu nome é: %s\nseu sobrenome é: %s\n",json_object_get_string(name),
   json_object_get_string(surname));




  return 0;
}
