#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "menu.h"

typedef struct {
  int top;
} Stack;

int main(void) {
  int menuChoice = mainMenu();
  switch(menuChoice) {
    case 1: registerMenu(); break;
    case 2: appointmentMenu(); break;
    case 3: exit(0); break;
    default: exit(1); break;
  }
}
