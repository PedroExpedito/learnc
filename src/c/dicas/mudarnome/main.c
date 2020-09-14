#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

// Estrutura do nó da lista.
struct node_s {
  struct node_s *next;
  char *name;
};

// Estrutura da lista.
struct list_s {
  struct node_s *head, *tail;
};

static int dirfiles( char *dirp, struct list_s *lstp )
{
  DIR *dp;
  struct dirent *direntp;

  // abre um "directory" stream.
  if ( !( dp = opendir( dirp ) ) )
    return 1; // erro.

  // Lê as entradas no diretório...
  while ( direntp = readdir( dp ) )
    // Só chama a função se for um arquivo regular.
    if ( direntp->d_type == DT_REG )
    {
      struct node_s *node;

      // Aloca espaço do novo nó.
      if ( ! ( node = malloc( sizeof *node ) ) )
      {
      error:
        closedir( dp );
        return 1;   // erro.
      }

      // Duplica o buffer da string porque a estrutura
      // dirent retornada por readdir() é estática.
      if ( ! ( node->name = strdup( direntp->d_name ) ) )
      {
        free( node );
        goto error;
      }

      // Adiciona na lista.
      node->next = NULL;
      if ( lstp->tail )
        lstp->tail->next = node;
      lstp->tail = node;
      if ( ! lstp->head )
        lstp->head = node;
    }

  // fecha o stream.
  closedir( dp );

  return 0; // sucesso.
}

int main( void )
{
  struct list_s list = { NULL, NULL };
  struct node_s *p, *q;

  errno = 0;
  if ( dirfiles( "./", &list ) )
  {
    perror( "dirfiles" );
    return EXIT_FAILURE;
  }

  // Percorre e lista, mostrando as strings.
  p = list.head;
  while ( p )
  {
    printf( "Found: %s\n", p->name );
    p = p->next;
  }

  // Libera o espaço usado pela lista.
  p = list.head;
  while ( p )
  {
    free( p->name );
    q = p->next;
    free( p );
    p = q;
  }

  return EXIT_SUCCESS;
}
