#include <err.h>
#include <json-c/json.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR(i, msg)                                                          \
  fprintf(stderr, "%s\n", msg);                                                \
  exit(i)

#include "headers/list-names.h"

typedef unsigned long long int ulli;

struct Funcionario {
  ulli id;
  char nome[50];
  char sobrenome[50];
  double salario;
  char area[2];
};

typedef struct Funcionario t_funcionario;

int main(int argc, char **argv) {

  if (argc < 2) {
    ERROR(EXIT_FAILURE, "Passe o arquivo como argumento");
  }

  FILE *data;

  data = fopen(argv[1], "r");

  if (data == NULL) {
    ERROR(1, "File Not Found");
  }

  //  tamanho do buffer
  fseek(data, 0, SEEK_END);

  // Não precisa de sizeof(char) em todas as arquituturas é um bit
  unsigned long long int bufferSize = ftell(data);
  char *buffer = malloc(bufferSize);

  // voltar ao inicio
  fseek(data, 0, SEEK_SET);

  // passar para o buffer
  fread(buffer, bufferSize, 1, data);
  // fechando arquivo
  fclose(data);

  struct json_object *parsed_json;

  struct json_object *funcionarios;
  struct json_object *areas;

  parsed_json = json_tokener_parse(buffer);

  json_object_object_get_ex(parsed_json, "funcionarios", &funcionarios);
  json_object_object_get_ex(parsed_json, "areas", &areas);

  struct json_object *funcionario;

  // JSON to array

  ulli arrayLenth = json_object_array_length(funcionarios);

  t_funcionario Funcionarios[arrayLenth];

  struct json_object *id;
  struct json_object *nome;
  struct json_object *sobrenome;
  struct json_object *salario;
  struct json_object *area;

  for (int i = 0; i < arrayLenth; i++) {
    funcionario = json_object_array_get_idx(funcionarios, i);

    json_object_object_get_ex(funcionario, "id", &id);
    Funcionarios[i].id = json_object_get_int64(id);

    json_object_object_get_ex(funcionario, "nome", &nome);
    strcpy(Funcionarios[i].nome, json_object_get_string(nome));

    json_object_object_get_ex(funcionario, "sobrenome", &sobrenome);
    strcpy(Funcionarios[i].sobrenome, json_object_get_string(sobrenome));

    json_object_object_get_ex(funcionario, "salario", &salario);
    Funcionarios[i].salario = json_object_get_double(salario);

    json_object_object_get_ex(funcionario, "area", &area);
    strcpy(Funcionarios[i].area, json_object_get_string(area));
  }

  // maior salario

  double salarioCorrente = Funcionarios[0].salario;
  double SomaSalarios = salarioCorrente;
  ulli idMaiorSalario = 0;

  for (ulli i = 1; i < arrayLenth; i++) {
    SomaSalarios += Funcionarios[i].salario;
    if (salarioCorrente < Funcionarios[i].salario) {
      salarioCorrente = Funcionarios[i].salario;
      idMaiorSalario = i;
    }
  }

  for (ulli i = 1; i < arrayLenth; i++) {
    if (Funcionarios[i].salario == Funcionarios[idMaiorSalario].salario) {
      printf("global_max|%s %s|%.2f\n", Funcionarios[i].nome,
             Funcionarios[i].sobrenome, Funcionarios[i].salario);
    }
  }

  // menor salario

  ulli idMenorSalario = 0;

  for (ulli i = 1; i < arrayLenth; i++) {
    if (salarioCorrente > Funcionarios[i].salario) {
      salarioCorrente = Funcionarios[i].salario;
      idMenorSalario = i;
    }
  }

  for (ulli i = 1; i < arrayLenth; i++) {
    if (Funcionarios[i].salario == Funcionarios[idMenorSalario].salario) {

      printf("global_min|%s %s|%.2f\n", Funcionarios[i].nome,
             Funcionarios[i].sobrenome, Funcionarios[i].salario);
    }
  }

  // global avg
  printf("global_avg|%.2f\n",(SomaSalarios / ((double) arrayLenth)));

  // area max

  ulli areasTamanho = json_object_array_length(areas);
  // Area para struct

  struct S_area {
    char codigo[3];
    char nome[100];
  };

  typedef struct S_area s_area;

  s_area list_area[areasTamanho];

  struct json_object *area2;
  struct json_object *area2_codigo;
  struct json_object *area2_nome;

  for ( unsigned int i = 0; i < areasTamanho; i++) {
    area2 = json_object_array_get_idx(areas, i);
    json_object_object_get_ex(area2, "nome", &area2_nome);
    json_object_object_get_ex(area2, "codigo", &area2_codigo);

    strcpy(list_area[i].codigo, json_object_get_string(area2_codigo));
    strcpy(list_area[i].nome, json_object_get_string(area2_nome));

    /* printf("Nome: %s, código: %s\n", list_area[i].nome, list_area[i].codigo); */
  }
  // area max

  ulli idDoMaiorDeCadaArea[areasTamanho];
  double maiorSalarioArea = -1;
  ulli idDoMaiorSalario;

  for ( unsigned int i = 0; i < areasTamanho; i++) {
    for (ulli j = 1; j < arrayLenth; j++) {
      if(strcmp(Funcionarios[j].area , list_area[i].codigo) == 0) {
        salarioCorrente = Funcionarios[j].salario;
        if(maiorSalarioArea < 0) {
          maiorSalarioArea = salarioCorrente;
          idDoMaiorSalario = j;
        }
        else if(maiorSalarioArea < salarioCorrente) {
          idDoMaiorSalario = j;
        }
      }
    }
    idDoMaiorDeCadaArea[i] = idDoMaiorSalario;
    maiorSalarioArea = -1;
  }

  printf("%s\n", Funcionarios[idDoMaiorDeCadaArea[0]].nome);
  printf("%s\n", Funcionarios[idDoMaiorDeCadaArea[1]].nome);
  printf("%s\n", Funcionarios[idDoMaiorDeCadaArea[2]].nome);


  return 0;
}
