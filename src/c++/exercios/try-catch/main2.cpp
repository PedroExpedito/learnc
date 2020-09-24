// tudo retorno diferente de 0 é erro
// try catch throw

#include <iostream>
#include <exception>
#include <string.h>

using namespace std;

class CustomException : public exception {
  protected:
    char msg[100];
  public:
    CustomException(const char* e) {
      strcpy(this->msg, e);
    }
    virtual const char* what() {
      return msg;
    }
};

int fat(int n) {
  if( n < 0 )
    throw CustomException("Numero negativo!!");
  if( n == 0 || n == 1)
    return 1;
  return n * fat(n -1);
}
int main(void) {
  try {
    cout << fat(-1) << endl;
  } catch(CustomException err) {
      cout << err.what() << endl;
  }
}
