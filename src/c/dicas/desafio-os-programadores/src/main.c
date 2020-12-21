#include <err.h>
#include <json-c/json.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>

#define ERROR(i, msg)                                                          \
  fprintf(stderr, "%s\n", msg);                                                \
  exit(i)

#include "headers/list-names.h"



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

void global_print(json_object *j_funcionarios) {
  unsigned int i;

  struct json_object *j_funcionario;
  struct json_object *j_salario;

  struct json_object *j_max_salary;
  struct json_object *j_min_salary;

  j_max_salary = json_object_new_array();
  j_min_salary = json_object_new_array();

  float currentSalary;
  float MaxSalary = 0;
  float MinSalary = FLT_MAX;
  float SumSalary = 0;

  for ( i = 0; i < funcionarios_length; i++ ) {
    j_funcionario = json_object_array_get_idx(j_funcionarios, i);
    json_object_object_get_ex(j_funcionario, "salario", &j_salario);
    currentSalary = json_object_get_double(j_salario);

    SumSalary += currentSalary;

    if( currentSalary > MaxSalary ) {
      j_max_salary = json_object_new_array();
      json_object_array_add(j_max_salary, j_funcionario);
      MaxSalary = currentSalary;
    } else if( currentSalary == MaxSalary) {
      json_object_array_add(j_max_salary, j_funcionario);
    }
    if( currentSalary < MinSalary) {
      MinSalary = currentSalary;
      j_min_salary = json_object_new_array();
      json_object_array_add(j_min_salary, j_funcionario);
    } else if( currentSalary == MinSalary) {
      json_object_array_add(j_min_salary, j_funcionario);
    }
  }

  // effetive print
  struct json_object *j_name;
  struct json_object *j_surname;
  struct json_object *j_salary;

  for ( i = 0; i < json_object_array_length(j_max_salary); i++) {
    j_funcionario = json_object_array_get_idx(j_max_salary, i);
    json_object_object_get_ex(j_funcionario, "nome", &j_name);
    json_object_object_get_ex(j_funcionario, "sobrenome", &j_surname);
    json_object_object_get_ex(j_funcionario, "salario", &j_salary);

    printf("global_max|%s %s|%.2f\n", json_object_get_string(j_name),
        json_object_get_string(j_surname), json_object_get_double(j_salary));
  }

  for ( i = 0; i < json_object_array_length(j_min_salary); i++) {
    j_funcionario = json_object_array_get_idx(j_min_salary, i);
    json_object_object_get_ex(j_funcionario, "nome", &j_name);
    json_object_object_get_ex(j_funcionario, "sobrenome", &j_surname);
    json_object_object_get_ex(j_funcionario, "salario", &j_salary);

    printf("global_min|%s %s|%.2f\n", json_object_get_string(j_name),
        json_object_get_string(j_surname), json_object_get_double(j_salary));
  }
  printf("global_avg|%.2f\n", SumSalary / (float) funcionarios_length);
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

    puts(json_object_get_string(j_code));

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


  // Definir antes de chamar quaquer thread
  funcionarios_length = json_object_array_length(j_funcionarios);

  global_print(j_funcionarios);
  area_print(j_funcionarios, j_areas);
  // JSON to array
}

