#include<stdio.h>
#include<string.h>

int main() {
  setLocale(LC_ALL,"Portuguese_Brasil");

  char emojib[5] = "😀\0";
    printf("%s",emojib);
}
/*

    printf("\nsão iguais\n");
  } else {
    printf("\nsão diferentes\n");
  }

  return 0;
}

int main(void){
  char bom[20] = "a";
  char bom2[20] = "a";

int res = strcmp(bom, bom2);

  printf("%d\n", res);
}*/


