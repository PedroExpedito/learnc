#ifndef FOO_H_
#define FOO_H_

#include <stdio.h>
#include <json-c/json.h>
#include <float.h>

void print(json_object *j_funcionarios, const char *escopo, const char *area) {
  unsigned int i;

  unsigned int funcionarios_length;
  funcionarios_length = json_object_array_length(j_funcionarios);

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

      printf("%s_max|%s%s %s|%.2f\n",escopo, area, json_object_get_string(j_name),
        json_object_get_string(j_surname), json_object_get_double(j_salary));
  }

  for ( i = 0; i < json_object_array_length(j_min_salary); i++) {
    j_funcionario = json_object_array_get_idx(j_min_salary, i);
    json_object_object_get_ex(j_funcionario, "nome", &j_name);
    json_object_object_get_ex(j_funcionario, "sobrenome", &j_surname);
    json_object_object_get_ex(j_funcionario, "salario", &j_salary);

    printf("%s_min|%s%s %s|%.2f\n",escopo, area, json_object_get_string(j_name),
        json_object_get_string(j_surname), json_object_get_double(j_salary));
  }
  printf("%s_avg|%s%.2f\n",escopo, area, SumSalary / (float) funcionarios_length);
}

#endif
