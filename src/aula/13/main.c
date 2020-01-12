#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, size) { \
    ptr = malloc(size); \
    if(ptr == NULL){ \
        fprintf(stderr,"memoria insuficiente\n"); \
        exit(1); \
    } \
}
void *malloc_s(size_t size){
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL){
        fprintf(stderr,"memoria insuficiente\n");
        exit(1);
    }
    return ptr;
}
int main (int argc, char *argv[]){
    int *p;
    MALLOC(p,9 * sizeof(int));
    if(p == NULL){
        return 1;
    }
    *p = 10;
    *(p+1) = 20;
    *(p+2) = 30;
    *(p+3) = 40;
    *(p+4) = 50;
    *(p+5) = 60;
    *(p+6) = 70;
    *(p+7) = 80;
    for (int i=0;i< 100;i++){
        printf("%d\n",*(p+i));
    } 
    free(p);
    return 0;
}