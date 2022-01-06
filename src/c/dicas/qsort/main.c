#include <stdio.h>
#include <stdlib.h>

int comparator(const void * a, const void *b) {
  // typecasting para int
  return *(int*)a - *(int*)b;
}

int main(void) {
  int arr[] = {15, 30, 10, 20, 25};

  qsort(arr, 5, sizeof(int), comparator);

  //mostra os valores do array
   for( int i = 0 ; i < 5; i++ ) {
      printf("%i ", arr[i]);
   }
   puts("");

   return(0);
}
