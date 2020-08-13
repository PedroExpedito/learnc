#include <stdio.h>

int main(void) {

    int X, Y;

    printf("DIGITE O NUMERO X: \n");
    scanf("%i", &X);

    printf("DIGITE O NUMERO Y: \n");
    scanf("%i", &Y);

    if(X - Y == 1) {

        printf(" sim, X sequencial de Y ");

    } else if (Y - X == 1) {

        printf(" sim, Y sequencial de X ");
    } else {

        printf(" DESCULPE, AMBOS OS NUMEROS NAO SAO SEQUENCIAIS ");

    };

    return 0;

}
