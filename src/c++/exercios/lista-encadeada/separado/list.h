//possui um valor e um ponteiro que aponta para a proxima celula
//a ultima celula aponta para VOID
//
//é utilizado na classe list que é duplamente encadeada
//
//Duplamente encadeada aponta tanto para o proximo e tanto para o anterior
//
//Linked list simple
#ifndef _LIST_H_
#define _LIST_H_


#include <iostream>

using namespace std;

template<class T>
class Node {
  private:
    T v;
    Node* next;
  public:
    Node(T v) {
      this-> v = v;
      this->next = NULL;
    }
    T get_value() {
      return v;
    }
    Node* get_next() {
      return next;
    }
    void setNext(Node* next) {
      this->next = next;
    }
};

template<class T>
class List {
  private:
    Node<T>* head;
    Node<T>* tail;
  public:
    List()
    {
      head = NULL;
      tail = NULL;
    }
    List(T v) {
      head = new Node<T>(v);
      tail = head;
    }

    virtual ~List() {
      delete head;
    }

    void get_node() {
      cout << "Imprimindo todos os elementos..\n";
      Node<T> *c = head;
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

    void push_front( T v) {
      Node<T>* newNode = new Node<T>(v);
      newNode->setNext(head);
      head = newNode;
    }
    void push_back(T v) {
      Node<T>* newNode = new Node<T>(v);
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
      Node<T>* c = head;
      T size = 0;

      do {
        c = c->get_next();
        size++;
      } while(c);
      return size;
    }

    bool includes(T v) {
      if (empty()) {
        return false;
      }
      Node<T>* c = head;

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
          Node<T>* oldOld = head;
          Node<T>* old = head->get_next();
          Node<T>* current = head->get_next()->get_next();

          while(current) {
            Node<T>* aux = old;
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
#endif
