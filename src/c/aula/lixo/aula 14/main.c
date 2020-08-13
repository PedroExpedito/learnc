#include <stdio.h>

struct st {
    unsigned char id[9000];
    unsigned int numero;
};
int main(void){
    struct st s;
    
    s.id[0] = 3;
    s.numero = 404;
    printf("%d",s.id);
    printf("%d\n",s.numero);
    printf("Tamanho da struct: %d\n",sizeof(struct st));
    
    return 0;
}