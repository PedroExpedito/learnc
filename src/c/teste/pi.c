#include<stdio.h>
int main(void){
  int base=17,space=0;
  while(base > 1){
    for(int j=0; j <= space;j++){
        printf(" ");
    }
    for (int i=0; i < base-2; i++){
      printf("*");
    }
    printf("\n");
        space += 1;
    base -= 2;
    }
  return 0;
}
