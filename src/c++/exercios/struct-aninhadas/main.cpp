// Struct aninhada são apenas struct dentro de structs

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct Course {
  char name[50];
  double price;
} t_course;

typedef struct Student {
  char name[50];
  Course course;
}t_student;

typedef struct People {
  struct Car {
    int price;
  };
  struct Home {
    int price;
    char *anddres;
  };
  struct Car car;
  struct Home home;
}t_people;
int main(void) {
  t_student s;

  strcpy(s.name, "Pedro");
  strcpy(s.course.name, "C++ para iniciantes");
  s.course.price = 10;

  cout << "Nome da pessoa: " << s.name << endl;
  cout << "Nome do curso: " << s.course.name << endl;
  cout << "Preço do curso: " << s.course.price << endl;

  t_people p1;

  p1.home.price = 2000;
  p1.home.anddres = ( char * ) malloc(sizeof(char) * strlen("Rua Mathias") + 1);
  strcpy(p1.home.anddres, "Rua Mathias");
  p1.car.price = 10000;

  cout << p1.home.anddres << endl;
  free(p1.home.anddres);



  return 0;
}
