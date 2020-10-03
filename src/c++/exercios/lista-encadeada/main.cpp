//possui um valor e um ponteiro que aponta para a proxima celula
//a ultima celula aponta para VOID
//
//é utilizado na classe list que é duplamente encadeada
//
//Duplamente encadeada aponta tanto para o proximo e tanto para o anterior
//
//Linked list simple
#include <iostream>

using namespace std;

class Node {
  private:
    int v;
    Node* next;
  public:
    Node(int v) {
      this-> v = v;
      this->next = NULL;
    }
    int get_value() {
      return v;
    }
    Node* get_next() {
      return next;
    }
    void setNext(Node* next) {
      this->next = next;
    }
};

class List {
  private:
    Node* head;
    Node* tail;
  public:
    List()
    {
      head = NULL;
      tail = NULL;
    }
    List(int v) {
      head = new Node(v);
      tail = head;
    }

    virtual ~List() {
      delete head;
    }

    void get_node() {
      cout << "Imprimindo todos os elementos..\n";
      Node *c = head;
      if ( empty()) {
        cout << "A lista esta vazia\n";
      } else {
        while(c) {
          cout << c->get_value() << endl;
          c = c->get_next();
        }
        cout << endl;

      }
    }

    bool empty() {
      return ( head == NULL);
    }

    void push_front( int v) {
      Node* newNode = new Node(v);
      newNode->setNext(head);
      head = newNode;
    }
    void push_back(int v) {
      Node* newNode = new Node(v);
      if(empty()) {
        head = newNode;
        tail = newNode;
        // throw "Lista vazia";
      } else {
        tail->setNext(newNode);
        tail = newNode;
      }
    }

    int size() {
      if (empty()) {
        return 0;
      }
      Node* c = head;
      int size = 0;

      do {
        c = c->get_next();
        size++;
      } while(c);
      return size;
    }

    bool includes(int v) {
      if (empty()) {
        return false;
      }
      Node* c = head;

      while(c){
        if ( c->get_value() == v ) {
          return true;
        }
        c = c->get_next();
      }
      return false;
    }

    void pop_back() {
      if(!empty()) {
        if(head->get_next() == NULL){
          head = NULL;
        } else if(head->get_next()->get_next() == NULL) {
          head->setNext(NULL);
        } else {
          Node* oldOld = head;
          Node* old = head->get_next();
          Node* current = head->get_next()->get_next();

          while(current) {
            Node* aux = old;
            old = current;
            oldOld = aux;
            current =current->get_next();
          }
          delete oldOld->get_next();
          oldOld->setNext(NULL);
          tail = oldOld;
        }
      }
    }

};
using namespace std;

int main(void) {
  List list;
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
