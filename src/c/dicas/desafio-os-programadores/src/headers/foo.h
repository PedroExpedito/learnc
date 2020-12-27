#ifndef FOO_H_
#define FOO_H_

#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>
#include <float.h>
#include <string.h>

typedef struct str_list {
  struct str_list *head;
  struct str_list *current;
  struct str_list *prox;
  char surname[50];
} Str_list;

Str_list *str_list_create() {
  Str_list *p = (Str_list *)malloc(sizeof(Str_list));

  if ( p == NULL ) {
    fprintf(stderr, "Error Alocate Memory\n");
    exit(1);
  }

  p->prox = NULL;
  p->head= NULL;
  p->current = NULL;

  return p;
}

void str_list_push(Str_list *list,const char *str) {
  if( list->head == NULL) {
    strcpy(list->surname, str);
    list->head = list;
    list->prox = NULL;
    list->current = list;
  } else {
    if(1) {
      Str_list *p = (Str_list *)malloc(sizeof(Str_list));
      if ( p == NULL ) {
        fprintf(stderr, "Error Alocate Memory\n");
        exit(1);
      }
      strcpy(p->surname,str);
      p->prox = NULL;
      list->current->prox = p;
      list->current = p;
    }
  }
}

int str_list_search(Str_list *list,const char *str) {
  Str_list *aux = list->head;

  while( aux != NULL) {
    if(strcmp(aux->surname, str) == 0) {
      return 1;
    }
    aux = aux->prox;
  }
  return 0;
}

void str_list_free(Str_list *list) {
  Str_list *head = list->head;
  Str_list *tmp;

  while(head != NULL) {
    tmp = head;
    head = head->prox;
    free(tmp);
  }
}


void print_last_name(json_object *j_funcionarios) {
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

  for ( i = 0; i < funcionarios_length; i++ ) {
    j_funcionario = json_object_array_get_idx(j_funcionarios, i);
    json_object_object_get_ex(j_funcionario, "salario", &j_salario);
    currentSalary = json_object_get_double(j_salario);


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

      printf("last_name_max|%s|%s %s|%.2f\n",
        json_object_get_string(j_surname),
        json_object_get_string(j_name),
        json_object_get_string(j_surname),
        json_object_get_double(j_salary));
  }
}


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


void area_print(json_object *j_funcionarios, json_object *j_areas) {

  unsigned int funcionarios_length;
  funcionarios_length = json_object_array_length(j_funcionarios);

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


  if (SD_length > SM_length && SD_length > UD_length) {
    printf("most_employees|Desenvolvimento de Software|%d\n", SD_length);
    if ( SM_length < UD_length) {
      printf("least_employees|Gerenciamento de Software|%d\n",SM_length);
    } else {
      printf("least_employees|Designer de UI/UX|%d\n",UD_length);
    }
  } else if ( SM_length > UD_length) {
    printf("most_employees|Gerenciamento de Software|%d\n", SM_length);
    if(UD_length < SD_length) {
      printf("least_employees|Designer de UI/UX|%d\n",UD_length);
    } else {
      printf("least_employees|Desenvolvimento de Software|%d\n",SD_length);
    }
  } else {
    printf("most_employees|Designer de UI/UX|%d\n", UD_length);
    if ( SM_length < SD_length) {
      printf("least_employees|Gerenciamento de Software|%d\n",SM_length);
    } else {
      printf("least_employees|Desenvolvimento de Software|%d\n",SD_length);
    }
  }
}

#endif
