#include <stdio.h>


typedef struct {
  long double numerador;
  long double denominador;
} Fraction;

Fraction Fmultiply(Fraction *f, Fraction *f2) {
  Fraction ret;
  ret.numerador = f->numerador * f2->numerador;
  ret.denominador = f->denominador * f2->denominador;
  return ret;
}

int main(void) {
  Fraction um;
  um.numerador = (long double)2;
  um.denominador = (long double)4;

  Fraction dois;
  dois.numerador = (long double)4;
  dois.denominador = (long double)8;

  Fraction tres = Fmultiply(&um,&dois);

  printf("Nemurador: %LF , Denominador: %LF", tres.numerador, tres.denominador);
}
