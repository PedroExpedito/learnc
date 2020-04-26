/* 2. Fazer uma função que calcula o fatorial de um número. Implementar uma
versão recursiva e uma versão com laço.
 ex  */
#include <stdio.h>
void erro();
unsigned long long int rfatorial(unsigned long long int  n);
unsigned long long int loop(unsigned long long n);
int main()
{
unsigned long long int n=0;
printf("Insira um valor para o qual deseja calcular seu fatorial: ");
scanf("%lld", &n);
if(n <= 20){
printf("%lld\n",loop(n));
}
else{erro();}
return 0;
}

unsigned long long int loop(unsigned long long int n){
    for(unsigned short int i = n; i > 1;i--){
        n = n * (i-1);
    }
return n;
}


unsigned long long int rfatorial(unsigned long long n)
{
  unsigned long long vfat;  
  if ( n <= 1 )
    return (1);
  else 
  {
    vfat = n * rfatorial(n - 1);
    return (vfat);
  }
}
void erro(){printf("Não é possivel calcular fatorial maior que 20!\n");}