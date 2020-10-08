// struct aninhada é quando a uma struct dentro de outra
#include <iostream>

using namespace std;

typedef struct Course {
  char name[50];
  double price;
} t_course;


typedef struct Student {
  char name[50];
  Course couse;

}t_student;
int main(void) {

}
