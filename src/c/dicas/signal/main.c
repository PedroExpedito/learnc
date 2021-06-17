#include <signal.h>
#include <stdio.h>

// man signal

// indica ao compilador para não otimizar, que outros programas podem mudar este valor.

static volatile int keepRunning = 1;

void intHandler(int dummy) {
    keepRunning = 0;
}

// ...

int main(void) {

   signal(SIGINT, intHandler);

   while (keepRunning) {
     puts("OI");
   }
  puts("Fechando...");
   return 0;
}
