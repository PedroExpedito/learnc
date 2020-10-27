/*
 * Lista de nomes simplesmente encadeada

Funcionalidades:

                1) - Criar lista 2) - Adicionar na lista 3) - Listar os elementos da lista
                4) - Verificar se a lista está vazia
                5) - Buscar elemento na lista
                6) - Remover elemento da lista
                7) - Verificar o tamanho da lista

Melhorias:
                * é precisa criar um objeto ao inves de uma lista global
                * Melhorar a strcpy padrão
*/


#ifndef Clist_H_
#define Clist_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct exemplo {
  char name[100];
  struct exemplo *prox;
} t_exemplo;

struct Clist{
  t_exemplo data;
  t_exemplo *head;
  t_exemplo *current;

  //func
  int (*size)(struct Clist*);
  int (*empty)(struct Clist*);
  t_exemplo *(*push)(struct Clist*,char*);
  void (*print)(struct Clist*);
  int (*pop)(struct Clist *,char*);
  void (*free)(struct Clist*);
};



typedef struct Clist Clist;

void clist_Contructor(Clist* list);



Clist *create_list(char* name) {
  Clist *p = (Clist *)malloc(sizeof(Clist));

  if (p == NULL) {
    printf("\nFalha ao alocar memoria\n");
    return NULL;
  }

  strcpy(p->data.name,name);

  p->data.prox = NULL;

  p->head = &p->data;
  p->current = &p->data;
  clist_Contructor(p);
  return p;
}

t_exemplo *push_list(Clist *list,char *name) {
  if (list->head == NULL) {
    fprintf(stderr, "list not create");
    exit(1);
  }
  t_exemplo *p = (t_exemplo *)malloc(sizeof(t_exemplo));

  if (p == NULL) {
    printf("\nFalha ao alocar memoria\n");
    return NULL;
  }

  strcpy(p->name , name);
  p->prox = NULL;

  list->current->prox = p;
  list->current = p;
  return p;
}

void print_list(Clist *list) {

  t_exemplo *aux = list->head;

  while (aux != NULL) {
    printf("%s\n", aux->name);
    aux = aux->prox;
  }
}


int empty_list(Clist *list) {
  if (list->head == NULL)
    return 1;
  return 0;
}

t_exemplo *search_element(Clist *list,char *name, t_exemplo **ant) {
  if (empty_list(list) == 1)
    return NULL;
  t_exemplo *p = list->head;
  t_exemplo *aux_ant = NULL;
  int achou = 0;
  while (p != NULL) {
    if (strcmp(p->name, name) == 0) {
      achou = 1;
      break;
    }
    aux_ant = p;
    p = p->prox;
  }

  if (achou == 1) {
    if (ant)
      *ant = aux_ant; // guarda "aux_ant"
    return p;
  }
  return NULL;
}

int pop_list(Clist *list,char *name) {
  t_exemplo *ant = NULL;
  t_exemplo *elem = search_element(list,name, &ant);
  if (elem == NULL)
    return 0;
  if (ant != NULL)
    ant->prox = elem->prox;

  if (elem == list->current)
    list->current = ant;

  if (elem == list->head)
    list->head = elem->prox;

  free(elem);
  elem = NULL;
  return 1;
}

int size_list(Clist *list) {
  if (empty_list(list))
    return 0;
  t_exemplo *aux = list->head;
  int tam = 0;
  while (aux != NULL) {
    tam++;
    aux = aux->prox;
  }
  return tam;
}

void  free_list(Clist *list) {
  t_exemplo *head = list->head;
  t_exemplo *tmp;

  while (head != NULL) {
    tmp = head;
    head = head->prox;
    free(tmp);
  }
}

// char **list_to_vector() {
//
//   char **vector;
//   t_exemplo *aux = head;
//   //
//   int size = size_list() + 1;
//   vector = (char **) malloc(sizeof(char *)*size);
//   //
//   int i = 0;
//
//   while (aux != NULL && i < size) {
//     vector[i] = (char *)malloc(strlen(aux->name)+1);
//     strcpy(vector[i], aux->name);
//     aux = aux->prox;
//     i++;
//   }
//   return vector;
// }


void clist_Contructor(Clist *list) {
  list->size = size_list;
  list->empty = empty_list;
  list->push = push_list;
  list->print = print_list;
  list->pop = pop_list;
  list->free = free_list;
}

#endif
