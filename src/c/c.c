#include <stdio.h>
int count;
void func1 (void);
void func2 (void);

int main (void)
{
  count = 100;
  func1();
}

void func1 (void)
{
    int temp;
    temp = count;
    func2();
    printf ("count e %d" , count);  /* No livro diz que aqui imprimira 100, só que só tá imprimindo 1.*/
}
void func2 (void)
{
    int count;
    for (count=1; count<10; count++)
      putchar ('.');
}
