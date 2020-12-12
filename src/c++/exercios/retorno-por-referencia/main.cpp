// retorno por referencia
// função que retorna uma referencia funciona como um alias
//
// Quando fazer?
//
// Quando tiver uma quantidade muito grande de informação para
// ser retornada
//
// Diferença entre ponteiro
//
// Uma referencia não aponta é mais como um apelido/alias para
// um método/valor
//
// Uma referencia não pode ser NULL
//
// A referencia precisa ser inicializada junto com a criação
//
// A referencia não pode fazer referencia para outro valor apos
// declarada
//

#include <iostream>

// C++ program to illustrate return by reference
using namespace std;

// Function to return as return by reference
int& returnValue(int& x)
{
    return x;
}

int main()
{
    int a = 20;
    int& b = returnValue(a);

    cout << "a = " << a
         << " The address of a is "
         << &a << endl;

    cout << "b = " << b
         << " The address of a is "
         << &b << endl;
    return 0;
}
