#include <stdio.h>
#include <stdlib.h>
void erro(char *err){
  printf("%s", err);
  exit(1);
}
int create(char *shortcut){
 #ifdef OS_Windows
    printf("ola estou no windows");
#else
    if(system("cp ~/Área\\ de\\ trabalho/") == 0)
      return 0;
    else if(system("cp atalho.desktop ~/Desktop") == 0)
      return 0;
    else
      erro("Não foi possivel realizar a operação");
#endif
  return 0;
}
int main(int argc, char *argv[])
{
  create("atalho.desktop");
}
