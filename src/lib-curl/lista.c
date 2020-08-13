 Alguém sabe como eu posso saber o valor de algo em C ?
 estou tentando fazer um script que lé um diretorio e grava em um array porém não estou
 conseguindo e não consigo debugar, por não saber oque é o "ent->d_name"

 em java script eu posso javar tipo de algo com o typeof poréme em C eu não sei como fazer

```
var a = 1
console.log(typeof(a));

e o resultado é number
```

```
#include <dirent.h>
#include <stdio.h>
#include <string.h>


int main() {
  DIR *dir;
  char path[] = "/home/pedro/";
  struct dirent *ent;
  char *array;

  if ((dir = opendir(path)) != NULL) {

    while ((ent = readdir(dir)) != NULL) {
      /* minha dificuldade é saber oque é
       * "ent->d_name" ai complica não sei se é um valor numero
       * texto, binario etc, aparentemente é texto porque o printf
       * consegue imprimir como tal */
      strcpy(array, ent->d_name); // não funciona

      printf("%s\n", ent->d_name);

    }

    closedir(dir);

  } else {
    perror("");
    return 0;
  }

  printf("%s", array);
}
```
