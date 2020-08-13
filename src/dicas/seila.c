#include <stdio.h>

int main(void){
  char A[] = "pedro";
  char B[] = "lapis";

  char *pA= A;
  char *pB = B;

  while(*pA != '\0') {// Repete o while até encontrar em pA o fim de string
         *pB++ = *pA++; // pB recebe pA e se Incrementam
      *pB = '\0';
  }
  printf("%s",B);
}
