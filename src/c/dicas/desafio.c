#include <stdio.h>

int main(void)
{
    static const int x = 255; // 0xff
    int y = x + 1;
    int* ptr;

    ptr = &x;
    *ptr = 17;

    ptr = &y;
    *ptr = x + 2;

    printf("%d\n", *ptr);
    printf("%d\n", x);
    return 0;
}
