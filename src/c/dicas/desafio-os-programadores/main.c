#include<json-c/json.h>
#include <stdio.h>

int main(int argc, char **argv) {
  FILE *data;
  char buffer[1024];

  struct json_object *parsed_json;

  struct json_object *name;
  struct json_object *surname;

  data = fopen("SimpleData.json", "r");
  fread(buffer, 1024, 1, data);
  fclose(data);

  parsed_json = json_tokener_parse(buffer);

  json_object_object_get_ex(parsed_json, "name", &name);
  json_object_object_get_ex(parsed_json, "surname", &surname);

  printf("Seu nome é: %s\nseu sobrenome é: %s\n",json_object_get_string(name),
   json_object_get_string(surname));




  return 0;
}
