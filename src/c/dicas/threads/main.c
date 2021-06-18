#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10


// function for use nanosleep
int nsleep(long miliseconds)
{
   struct timespec req, rem;

   if(miliseconds > 999)
   {
        req.tv_sec = (int)(miliseconds / 1000);                            /* Must be Non-Negative */
        req.tv_nsec = (miliseconds - ((long)req.tv_sec * 1000)) * 1000000; /* Must be in range of 0 to 999999999 */
   }
   else
   {
        req.tv_sec = 0;                         /* Must be Non-Negative */
        req.tv_nsec = miliseconds * 1000000;    /* Must be in range of 0 to 999999999 */
   }

   return nanosleep(&req , &rem);
}


void *function(void *arg) {
  int *valor = (int *)(arg);

  int i;


  if (*valor == 1) {
    for (i = 0; i < SIZE / 2; i++) {
      puts("CHEGOU... Thread #01");
      nsleep(1000);
    }
  } else {
    for (i = SIZE / 2; i < SIZE; i++) {
      nsleep(1000);
      puts("CHEGOU... Thread #02");
    }
  }
  pthread_exit(EXIT_SUCCESS);
}

int main(void) {
  // declarando threads
  pthread_t t1, t2;

  // valores data qualquer
  int a1 = 1;
  int a2 = 2;

  // criando a tread
  // recebe a thread, atributos de encademaneto, a funcao, e o data
  // a função deve retornar um ponteiro void e retornar um ponteiro void

  if(pthread_create(&t1, NULL, function, (void *)(&a1))) {
    perror("thread #01");
    exit(EXIT_FAILURE);
  }
  if(pthread_create(&t2, NULL, function, (void *)(&a2))) {
    perror("thread #02");
    exit(EXIT_FAILURE);
  }

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  puts("terminou");

  return EXIT_SUCCESS;
}
