/*
 * Faça um programa no qual o professor entra com as notas das avaliações de
 * cada aluno de uma turma,
calcula e imprima a nota final (média das notas em cada avaliação) e a situação
do aluno: Aprovado se nota final maior ou igual a 60 ou Reprovado caso
contrário. A quantidade de avaliações deve ser informada pelo professor no
inicio o programa. O programa deve ter uma condição de parada controlada pelo
usuário para terminar de entrar com notas de alunos. Ao final imprimir a média
da turma. */

// Analise de requitos
//
// Classe Student:
//
// calcular media final
//
// verificar se foi aprovado ou reprovado
//
// Numero de alunos é dinamico!
//
// Imprimir media da turma.
//
// quantidade de avaliações é informada pelo professor

#include <iostream>

using namespace std;

class Student {
  private:
    double media;
    int avali;
    double *nota;
  public:
    Student() {
      this->avali = -1;
      nota = new double[avali];
      media = -1;
    }
    ~Student() {
      delete[] nota;
    }
    double getNota(int posi) {
      return nota[posi];
    }
    void setNotas() {
      int nota;
      for ( int i = 0; i < avali; i++) {
      cout << "Nota Avaliação: " << i << "º" << endl;
      cin >> nota;
      this->nota[i] = nota;
      }
    }

    void setAvali() {
      cin >> this->avali;
    }
    double getMedia() {
      if ( media == -1) {
      double sum;
      for( int i = 0; i < avali; i++) {
        sum += this->nota[i];
      }

      this->media = (sum / avali);

      return this->media;
      } else {
        return this->media;
      }
    }

};


int main(void) {
  int avali = 0;

  cout << "Quantidade de meterias" << endl;
  cin >> avali;
  Student student[10];




}
