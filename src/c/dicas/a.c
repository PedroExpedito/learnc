#include <stdio.h>
#include <string.h>


#define SIZE 3
typedef struct {
  char name[100];
  int age;
} People;

People peoples[SIZE];
void populate() {
  strcpy(peoples[0].name, "Pedro");
  strcpy(peoples[1].name, "Marcos");
  strcpy(peoples[2].name, "Lucas");
  peoples[0].age = 10;
  peoples[1].age = 20;
  peoples[2].age = 30;
}

int searchName(char *name) {
  for ( int i = 0; i < 3; i++ ) {
    if ( strcmp(peoples[i].name, name) == 0){
      return i;
    }
  }
  return -1;
}
int main(void) {
  populate();
  int result = searchName("Pablo");
  printf("%d", result);

  return 0;
}
