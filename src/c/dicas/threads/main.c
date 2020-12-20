#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int v[SIZE];

void *function(void *arg) {
  int *valor = (int *)(arg);

  int i;

  if (*valor == 1) {
    printf("Thread 1 Executando...\n");
    for (i = 0; i < SIZE / 2; i++) {
      v[i] = 1;
    }
  } else {
    printf("Thread 2 Executando...\n");
    for (i = SIZE / 2; i < SIZE; i++) {
      puts("CHEGOU");
      v[i] = 2;
    }
  }
}

int main(void) {
  pthread_t t1, t2;

  int a1 = 1;
  int a2 = 2;

  pthread_create(&t1, NULL, function, (void *)(&a1));
  pthread_create(&t2, NULL, function, (void *)(&a2));

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  for (int i = 0; i < SIZE; i++) {
    printf("%d\n", v[i]);
  }

  exit(0);
}
