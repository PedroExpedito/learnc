#include <stdio.h>
#include <stdlib.h>

struct Arv {
  int info;
  struct Arv *sae;
  struct Arv *sad;
};

typedef struct Arv Arv;

Arv *create_arv(void) { return NULL; }

int empty_arv(Arv *arv) {
  if (arv == NULL) {
    return 1;
  }
  return 0;
}

Arv *create_and_element(int c, Arv *sae, Arv *sad) {
  Arv *p = (Arv *)malloc(sizeof(Arv));
  p->info = c;
  p->sae = sae;
  p->sad = sad;
  return p;
}
void print_arv(Arv *a) {
  if (!empty_arv(a)) {
    printf("%d", a->info);
    print_arv(a->sae);
    print_arv(a->sad);
  }
}

Arv *free_arv(Arv *a) {
  if (!empty_arv(a)) {
    free_arv(a->sae);
    free_arv(a->sad);
    free(a);
  }
  return NULL;
}
int busca(Arv *a, int c) {
  if (empty_arv(a))
    return 0; /* árvore vazia: não encontrou */
  else
    return a->info == c || busca(a->sae, c) || busca(a->sad, c);
}

int main(void) {
  Arv *a1 = create_and_element(8, create_arv(), create_arv());
  print_arv(a1);
  printf("\n%d", busca(a1, 9));
  free_arv(a1);
}
