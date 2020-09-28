#include <stdio.h>
#include <stdlib.h>

#define ERROR(msg) printf(msg); exit(1);

typedef struct {
  int value;
} Data;

typedef struct {
  Data data;
  Data *next;
} Elemento;

Elemento TOPO;

void stackPush(int value) {

}
Elemento stackCreate() {
  if(TOPO.next == NULL) {
    ERROR("Pilha já existe");
  } else {
  }
}
int main(void) {

  stackCreate();

  return 0;
};
