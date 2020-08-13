#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


void erro(string err){
  cout << err <<endl;
  exit(1);
}
int create(){
 #ifdef OS_Windows
    printf("ola estou no windows");
#else
    if(system("cp atalho.desktop ~/Área\\ de\\ trabalho/") == 0)
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
  create();
}
