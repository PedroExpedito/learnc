#include <iostream>

// Não é permitido criar operadores
// Só permite novas deficinoçoes para operadores que já existem
// Alguns operados não podem ser sobrecarregado exemplo o ::
// o operador não pode ser binario para unario
// não se pode afetar a precedencia de operadores
//

// ====== Numeros Complexos ====
// A necessidade dos numeros complexos veio a partir de um numero negativo não ter raiz
// quadrada. Sendo um numero complexo um numero que Z que pode ser escrito na forma Z= X + Yi,
// sendo x e y numeros reais e i uma unidade imaginaria. Esta tem propiedade i² = -1, sendo que x
// e y são chamados respectivamente parte real e parte imagina de Z.
//
// Regras:
//
// é preciso somar parte real com parte real e parte imaginaria com parte imaginaria
//
// n1 = 1 + 2i
// n2 = 3 + 4i
//
// n3 = n1 + n2
//
// n3 = 4 + 6i
//
// C++ Não suporta numero complexo primitivo



class Complexo {
  public:
    int real, imag;
    Complexo(int real, int imag) {
      this->real = real;
      this->imag = imag;
    }
    // sobrecarregando o operador +
    // o operadores são em si uma função

    Complexo operator+(Complexo& c) {
      // no caso ele recebe o valor de c2 que é o segundo a ser passado
      return Complexo(this->real + c.real, this->imag + c.imag);
    }
};
class People {
  private:
    int credito;
    int debito;
  public:
    People(int credito, int debito){
      this->credito = credito;
      this->debito = debito;
    }

    People operator+(People& p) {
      return People(this->credito + p.credito,this->debito + p.debito);
    }
    int getCredito() {
      return this->credito;
    }
    int getDebito() {
      return this->debito;
    }

};

int main(int argc, char *argv[]) {
  // Complexo c1(1,2), c2(3,4);
  // Complexo c3 = c1 + c2;
  // std::cout << "REAL: " << c3.real << ", Imaginaria: " << c3.imag << std::endl;
  People p1(100,200), p2(300,100);
  People p3 = p1 + p2;
  std::cout << "Divida: " << p3.getCredito() << ", Debito: " << p3.getDebito() << std::endl;

  return 0;
}
