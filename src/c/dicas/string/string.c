#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct String {
  char *data;
  void (*set)(struct String *, char *);
  void (*append)(struct String *, char *);

} String;

void set_str(String *string, char str[]) {
  string->data = (char *)malloc(sizeof(char) * strlen(str) + 1);
  strcpy(string->data, str);
}
void append_str(String *string, char str[]) {
  strncat(string->data, str, strlen(str));
}
void clear_str(String *string) {
  free(string);
}
long long int size_str(String *string) {
  return strlen(string->data);
}
long long int length_str(String *string) {
  return strlen(string->data);
}
long long int max_size_str(String *string) {
  return sizeof(string->data);
}

void contructor(String *string) {
  string->set = set_str;
  string->append = append_str;
}
int main(void) {
  String str;
  contructor(&str);
  str.set(&str, "pedro");
  str.append(&str," Expedito");
  printf("valor: %lld\n", max_size_str(&str));
  puts(str.data);
}

