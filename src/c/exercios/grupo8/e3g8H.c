#include <stdio.h>

typedef struct {int avg, min,max; } Result;

Result calc(int* arr) {
  int acc,min,max,i=1;

  acc = min = max = arr[0];

  while(arr[i] >= 0) {
    acc += arr[i];
    if(arr[i] < min) { min = arr[i]; }
    else if(arr[i] > max) { max = arr[i];}
    i++;
  }
acc += arr[i];
i++;
return (Result) {
  .avg = acc / i,
  .min = min,
  .max = max,
};
}

int main(void){

  int array[10] = {10, 0, 8, 7, 0, 5, 4, 3, 2, -1};

  Result r = calc(array);
  printf("Media: %d, Minimo: %d,Maximo: %d \n", r.avg,r.min,r.max);

}
