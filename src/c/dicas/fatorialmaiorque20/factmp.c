// Compilar com:
//    cc -O2 -o factmp factmp.c -lgmp
//
// Não esquecer de instalar libgmp-dev.
//
// Quem me mostrou Frederico Pissarra
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <errno.h>
#include <time.h>

int main(int argc, char *argv[])
{
  char *p;
  mpz_t r;
  unsigned long n, c, total;
  time_t t1, t2;

  if ( ! *++argv )
  {
    fputs("Usage: factmp <value>\n", stderr);
    return EXIT_FAILURE;
  }

  errno = 0;
  n = strtoul( *argv, &p , 10 );
  if ( errno == ERANGE || *p )
  {
    fputs( "ERROR: Invalid value.\n", stderr );
    return EXIT_FAILURE;
  }

  mpz_init_set_ui(r, 1);             // resultado.

  t1 = time( NULL );

  c = 0;
  total = n;
  while ( n >= 1 )
  {
    mpz_mul_ui( r, r, n-- );
    fprintf( stderr, "%.2f%% complete... \r",
      100.0 * (double)++c / total );
  }

  t2 = time( NULL );

  mpz_out_str( stdout, 10, r );
  putchar('\n');

  mpz_clear(r);

  fprintf( stderr, "Total time: %lu seconds.\n",
    t2 - t1 );

  return EXIT_SUCCESS;
}

