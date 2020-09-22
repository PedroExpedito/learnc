/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Stack.hpp
 * Author: oliveira
 *
 * Created on 21 de setembro de 2020, 12:22
 */

#ifndef STACK_HPP
#define STACK_HPP

template <typename Type>
class Stack {
  private:
    Type* vet;
    int maxStack;
    int top;

  public:

    Stack(int size);
    ~Stack(){};

    void push(Type e);
    void pop();
    Type getTop();
    bool empty();
};

#endif /* STACK_HPP */

