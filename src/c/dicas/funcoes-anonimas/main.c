// SAI FORA DO PADRÂO ISO

#include <stdio.h>
#include <stdlib.h>

#define lambda(return_type, body_and_args) \
    ({                                     \
        return_type __fn__ body_and_args   \
            &__fn__;                       \
    })

void map(int array[], int n, int (*fn)(int)) {
    int i;
    for(i = 0; i < n; i++)
        array[i] = (*fn)(array[i]);
}

int main() {
    int *array;
    int nums;

    puts("Quantos numeros");
    scanf("%d", &nums);

    array = malloc(sizeof(int) * nums);

    for( int i = 0; i < nums; i++ ) {
      printf("Dijite o numero %d\n", i+1);
      scanf("%d", &array[i]);
    }


    int soma = 0;


    map(array, nums, lambda(int, (int x) { soma += x; return x; }));

    printf("%d\n", soma);
    free(array);

    return 0;
}
