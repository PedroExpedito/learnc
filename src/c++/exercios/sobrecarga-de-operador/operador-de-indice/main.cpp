// Sobrecarregar operador de indice

#include <iostream>
#include <stdlib.h>

using namespace std;

class Vector {
  private:
    int *vet, *vet_pos;
    int max;

  public:
    Vector(int max = 100)
    {
      if(max < 0) {
        cerr << "Error: indice tem que ser maior que 0" << endl;
        exit(1);
      } else if(max > 100) {
        cerr << "Erro: Maximo 100" << endl;
        exit(1);
      }
      this->max = max;

      // alocando
      vet = (int*)malloc(max * sizeof(int));
      vet_pos = (int*)malloc(max * sizeof(int));

      for( int i = 0; i < max; i++) {
        vet_pos[i] = 0;
      }
    }
    ~Vector() {
      delete[] vet;
      delete[] vet_pos;
    }

    bool insert(int e, int pos) {
      if(pos < max && pos >= 0)
      {
        vet[pos] = e;
        vet_pos[pos] = 1;
        return true;
      }
      return false;
    }
    // sobrecarregando
    //
    int& operator[](int i) {
      if ( i < 0 || i >= max) {
        cerr << " Error: Acesso invalido ao vetor.\n";
        exit(1);
      } else if (vet_pos[i] == 0) {
        cerr << "Não há elemento no vetor\n";
        exit(1);
      }
      return vet[i];
    }

    int size() {
      int size = 0;
      for( int i = 0; i < max; i++) {
        if(vet_pos[i] == 1) {
          size++;
        }
      }
      return size;
    }
};

int main(void) {
  Vector v(10);

  if(v.insert(10, 0)) {
    cout << "elemento inserido\n";
  }
  cout << v[0] << endl;
  cout << v.size() << endl;
  cout << v[3] << endl;

  return 0;
}
