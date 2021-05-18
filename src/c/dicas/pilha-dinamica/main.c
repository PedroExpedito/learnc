#include <stdio.h>
#include <stdlib.h>

/* dynamic stack */

#include <stdio.h>
#include <stdlib.h>

struct node {
  char data;
  struct node *next;
};

struct node *top = NULL;

void push(char item) {
  struct node *nptr = malloc(sizeof(struct node));
  nptr->data = item;
  nptr->next = top;
  top = nptr;
}

void pop() {
  if (top == NULL) {
    printf("\n\nStack is empty ");
  } else {

    struct node *temp;

    while (top != NULL) {
      temp = top;
      top = top->next;
      printf("%c", temp->data);
      free(temp);
    }
  }
}

int main() {
  /* push('o'); */
  /* push('r'); */
  /* push('d'); */
  /* push('e'); */
  /* push('p'); */
  push('\0');
  pop();
  return 0;
}
