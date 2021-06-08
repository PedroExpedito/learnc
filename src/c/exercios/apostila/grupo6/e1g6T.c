#include <stdio.h>
#include <stdlib.h>
int compara(const void* x, const void* y)
{
    if ( *(int*)x > *(int*)y )
       return 1;
    else if ( *(int*)x == *(int*)y )
            return 0;
    else if ( *(int*)x < *(int*)y )
            return -1;
}
int main(void){
  int a[5] = {8,4,3,5,2};
  qsort(a,(size_t)5,sizeof(int),compara);
  printf("Vetor depois da ordenação...\n");

  for ( unsigned short int aux = 0; aux < 5; aux++ ){
    printf("%4d",a[aux]);
    printf("\n");
  }
 return 0;
 }