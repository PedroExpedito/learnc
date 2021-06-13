#include <stdio.h>

// Enums é bem simples demorei para saber que C tinha enum erro meu podia ter ido tirado
// ler o std
// ex: basíco

enum dia_da_semana { Domingo = 1 , Segunda, Terca, Quarta, Quinta, Sexta, Sabado};

int dia = 2;

// é um enumadorador normalmente começa de 0, na maioria dos compiladores é
// unsingned int

int main(void) {

  switch(dia) {
  case Domingo:
    puts("Domingo");
    break;
  case Segunda:
    puts("Segunda");
    break;
  case Terca:
    puts("Terca");
    break;

  }
}

