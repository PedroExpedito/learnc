#include <stdio.h>

typedef struct Agenda {
  int Matricula;
  char Nome[40];
  struct Telefone *telefone_do_aluno;
  char Email[50];
  char Curso[40];
  struct Disciplina *disciplina_do_aluno;
  struct Agenda *ProxAgenda;
} Contato;

struct Telefone {
  char telefoneAluno[12];
  struct Telefone *ProxTelefone;
};

struct Disciplina {
  char disciplinaAluno[40];
  struct Disciplina *ProxDisciplina;
};

void Imprimir(Contato *Ponteiro) {
  Contato *Auxiliar;
  Auxiliar = Ponteiro;
  if (Auxiliar != NULL) {
    printf("Matricula: %i\n", Auxiliar->Matricula);
    printf("Nome: %s\n", Auxiliar->Nome);
    printf("Email: %s\n", Auxiliar->Email);
    printf("Curso: %s\n", Auxiliar->Curso);
    Imprimir(Auxiliar->ProxAgenda);
  }
}

void Inserir(Contato **Ponteiro) {

  Contato *novo = NULL;
  novo = (Contato *)malloc(sizeof(Contato));

  novo->Matricula = 1;

  printf("Nome: ");
  setbuf(stdin, NULL);
  scanf("%[^\n]s", novo->Nome);

  printf("Email: ");
  setbuf(stdin, NULL);
  scanf("%[^\n]s", novo->Email);

  printf("Curso: ");
  setbuf(stdin, NULL);
  scanf("%[^\n]s", novo->Curso);

  if (*Ponteiro == NULL) {
    novo->ProxAgenda = NULL;
    *Ponteiro = novo;
  } else {
    novo->ProxAgenda = *Ponteiro;
    *Ponteiro = novo;
  }
}

int main() {
  Contato *PonteiroAgenda = NULL;

  Inserir(&PonteiroAgenda);

  Imprimir(PonteiroAgenda);
}
