// Constantes em CPP 
#include <iostream>
#include <stdlib.h>

using namespace std;


int main(int argc, char * argv[]){
    const double PI = 3.1415;
    const double* p = &PI;
    malloc(sizeof(int));      
    cout << *p << endl;
}

