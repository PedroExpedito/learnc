/* esse programa aloca memoria a todo momente e deixa o maquina muita lenta
 * faz parecer que travou*/

#include <stdio.h>
#include <stdlib.h>
int main(void){
    int *p,*a,*b,*c;
    while (1)
    {
        a = malloc(16711568);
        b = malloc(16711568);
        c = malloc(16711568);
        p = malloc(16711568);
        p = malloc(16711568);
    }

    system("PAUSE");

}
