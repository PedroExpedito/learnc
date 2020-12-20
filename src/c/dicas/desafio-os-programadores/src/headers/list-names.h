#ifndef LIST_NAMES_H
#define LIST_NAMES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR2(i, msg)                                                         \
  fprintf(stderr, "%s\n", msg);                                                \
  exit(i)

typedef struct list_names {
  char name[100];
  char sobrenome[100];
  double salary;
  unsigned long long int id;
  char area[2];

  struct list_names *head;
  struct list_names *current;
  struct list_names *prox;
} list_names;

void push_list_names(list_names *list, unsigned long long int id,
                     const char *name, const char *sobrenome, double salary,
                     const char *area) {
  if (list->head == NULL) {
    // list->name = (char *) malloc(strlen(name) +1);

    list->id = id;
    strcpy(list->name, name);
    strcpy(list->sobrenome, sobrenome);
    list->salary = salary;
    strcpy(list->area, area);

    list->prox = NULL;
    list->head = list;
    list->current = list;

  } else {
    list_names *new_list = (list_names *)malloc(sizeof(list_names));
    if (new_list == NULL) {
      ERROR2(1, "Erro ao alocar memoria lista");
    }
    list->id = id;
    strcpy(list->name, name);
    strcpy(list->sobrenome, sobrenome);
    list->salary = salary;
    strcpy(list->area, area);

    new_list->prox = NULL;
    list->current->prox = new_list;
    list->current = new_list;
  }
}

void free_name_list(list_names *list) {
  list_names *head = list->head;
  list_names *tmp;

  while (head != NULL) {
    tmp = head;
    head = head->prox;
    free(tmp);
  }
}

void print_name_list(list_names *list) {
  list_names *head = list->head;

  while (head != NULL) {
    printf("global_max|%s %s|%f", head->name,head->sobrenome, head->salary);
    head = head->prox;
  }
  free(head);
}

list_names *create_list_names() {
  list_names *list = (list_names *)malloc(sizeof(list_names));

  if (list == NULL) {
    ERROR2(1, "falha ao alocar memoria");
  }
  list->prox = NULL;
  list->head = NULL;
  list->current = NULL;
  return list;
}

#endif
