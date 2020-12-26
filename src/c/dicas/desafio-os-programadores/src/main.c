#include <err.h>
#include <json-c/json.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>

#define ERROR(i, msg)                                                          \
  fprintf(stderr, "%s\n", msg);                                                \
  exit(i)

#include "headers/foo.h"



// Global Vars
unsigned int funcionarios_length;

struct Funcionario {
  unsigned int id;
  char nome[50];
  char sobrenome[50];
  double salario;
  char area[2];
};

struct Area {
    char codigo[3];
    char nome[100];
};

typedef struct Funcionario t_funcionario;
typedef struct Area t_area;

unsigned int get_file_size(FILE *file) {
  fseek(file, 0, SEEK_END);
  unsigned int ret  = ftell(file);
  fseek(file, 0, SEEK_SET);
  return ret;
}


void area_print(json_object *j_funcionarios, json_object *j_areas) {

  struct json_object *j_SD;
  struct json_object *j_SM;
  struct json_object *j_UD;

  struct json_object *j_funcionario;
  struct json_object *j_code;

  j_SD = json_object_new_array();
  j_SM = json_object_new_array();
  j_UD = json_object_new_array();
  unsigned int i;

  char code[3];

  for( i = 0; i < funcionarios_length; i++) {
    j_funcionario = json_object_array_get_idx(j_funcionarios, i);
    json_object_object_get_ex(j_funcionario, "area", &j_code);

    strcpy(code,json_object_get_string(j_code));


    if(strcmp(code, "SD") == 0) {
      json_object_array_add(j_SD,j_funcionario);
    }

    else if(strcmp(code, "SM") == 0) {
      json_object_array_add(j_SM,j_funcionario);
    }
    else {
      json_object_array_add(j_UD,j_funcionario);
    }
  }

  // effetive print MAX
  print(j_SM,"area", "Gerenciamento de Software|");
  print(j_UD,"area", "Designer de UI/UX|");
  print(j_SD,"area", "Desenvolvimento de Software|");

  unsigned int SD_length = json_object_array_length(j_SD);
  unsigned int SM_length = json_object_array_length(j_SM);
  unsigned int UD_length = json_object_array_length(j_UD);


  printf("%lu\n",json_object_array_length(j_SD));
  printf("%lu\n",json_object_array_length(j_SM));
  printf("%lu\n",json_object_array_length(j_UD));

}

int main(int argc, char **argv) {
  if (argc < 2) {
    ERROR(EXIT_FAILURE, "Passe o arquivo como argumento");
  }
  FILE *data;
  data = fopen(argv[1], "r");
  if (data == NULL) {
    ERROR(1, "File Not Found");
  }
  unsigned int bufferSize = get_file_size(data);
  char *buffer = malloc(bufferSize);
  fread(buffer, bufferSize, 1, data);
  fclose(data);

  struct json_object *parsed_json;
  struct json_object *j_funcionarios;
  struct json_object *j_areas;

  parsed_json = json_tokener_parse(buffer);

  json_object_object_get_ex(parsed_json, "funcionarios", &j_funcionarios);
  json_object_object_get_ex(parsed_json, "areas", &j_areas);


  funcionarios_length = json_object_array_length(j_funcionarios);

  print(j_funcionarios,"global","");
  area_print(j_funcionarios, j_areas);
}

