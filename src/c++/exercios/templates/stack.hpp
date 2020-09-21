// Template precisa ser implementado no Header
#include <stdlib.h>

template <class Type>

class Stack {
  private:
    Type* vet;
    int maxStack;
    int top;
  public:
    Stack(Type size){
      vet = new Type[size];
      maxStack = size -1;
      top = -1;
    }
    ~Stack() {
      delete [] vet;
    }
    void push(Type e){
      if ( top == maxStack ) {
        exit(1);
      } else {
        vet[++top] = e;
      }
    }
    void pop(){
      if(top == -1) {
        exit(1);
      } else {
        top--;
      }
    }

    Type getTop(){
      if ( top != -1) {
      return vet[top];
      } else {
        exit(1);
      }
    }
    bool empty() {
      return ( top == -1 );
    };
};


