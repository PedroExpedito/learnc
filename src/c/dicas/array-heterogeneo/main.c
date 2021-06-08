#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 1000

typedef struct dadosVD {
  int tam;
  int ocupacao;
  void**vetor;
} TdadosVD;

TdadosVD *criarVD() {
  TdadosVD *vd = malloc(sizeof(TdadosVD));

  vd->tam = 0;
  vd->ocupacao = 0;
  vd->vetor = malloc(sizeof(void*) *vd->tam);

  return vd;
}

void* acessarVD(TdadosVD *vd, int pos) {

  void* carga = NULL;

  if(pos <= vd->tam && pos >= 0) {
    carga = vd->vetor[pos];
  } else {
    puts("acesso fora do limite");
    exit(0);
  }

  return carga;
}

void inserirVD(TdadosVD *vd, void* carga, int pos) {

  if(pos >= vd->tam) {
    vd->tam++;
    vd->vetor = realloc(vd->vetor, sizeof(void*)*(vd->tam));
    vd->vetor[pos] = carga;
    vd->ocupacao++;
  }
}

// apenas diminui tam e seta o ponteiro para NULL
void removerVD(TdadosVD *vd, int pos) {
  if (pos >= vd->tam) {
    vd->tam--;
    vd->vetor[pos] = NULL;
    /* memmove(&vd->vetor[pos], &vd->vetor[pos +1], vd->tam - pos); */
  }
}

void freeVD(TdadosVD *vd) {
  free(vd->vetor);
  free(vd);
}


int main(){

  int inteiro = 100;
  char *string = "Nome Qualquer";

  TdadosVD *heterogeneo = criarVD();

  inserirVD(heterogeneo, &inteiro, 0);
  inserirVD(heterogeneo, string, 1);


  printf("inteiro: %d  e string: %s\n",
      *(int*)(acessarVD(heterogeneo,0)), acessarVD(heterogeneo, 1));


  free(heterogeneo);
  return 0;
}

