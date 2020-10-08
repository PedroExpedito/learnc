//possui um valor e um ponteiro que aponta para a proxima celula
//a ultima celula aponta para VOID
//
//é utilizado na classe list que é duplamente encadeada
//
//Duplamente encadeada aponta tanto para o proximo e tanto para o anterior
//
//Linked list simple
#include <iostream>
#include "list.h"

using namespace std;

int main(void) {
  List<int> list;
  if(list.empty()) {
    cout << "Lista vazia" << endl;
  } else {
    cout << "Lista vazia" << endl;
  }
  list.push_back(10);
  list.push_back(20);
  list.push_back(30);
  list.push_back(40);
  list.push_front(40);
  list.pop_back();

  list.get_node();
  cout << list.includes(10);

}
