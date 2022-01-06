#include <stdio.h>
#include <stdlib.h>

struct Vector2D {
  int x;
  int y;
};


void *vector_soma(void *x, void *y) {
  struct Vector2D* vx = (struct Vector2D*) x;
  struct Vector2D* vy = (struct Vector2D*) y;

  struct Vector2D* vz = malloc(sizeof(struct Vector2D));

  vz->x = vx->x + vy->x;
  vz->y = vx->y + vy->y;
  
  return (void*) vz;
}

void *int_soma(void *x, void *y) {
  int *result = malloc(sizeof(int));

  *result  = *((int *) x) + *((int *) y);

  return (void*)result;
}

void *soma(void *x, void* y, void *(_soma)(void*, void*)) {
  return _soma(x,y);
}

int main() {
  int x = 1, y =2;
  int *valor = (int*) soma((void *)&x,(void *) &y, int_soma);
  printf("Valor: %d\n", *valor);
  free(valor);
}
