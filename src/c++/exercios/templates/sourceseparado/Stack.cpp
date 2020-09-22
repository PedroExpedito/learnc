/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Stack.hpp"
#include "iostream"

template class Stack<int>;
template class Stack<double>;

template<typename Type>
Stack<Type>::Stack(int size)
{
      vet = new Type[size];
      maxStack = size -1;
      top = -1;
}


template<typename Type>
void Stack<Type>::push(Type e)
{


}

template<typename Type>
void Stack<Type>::pop()
{
  std::cout << "ola" << '\n';

}

template<typename Type>
Type Stack<Type>::getTop()
{
    return Type{};
}

template<typename Type>
bool Stack<Type>::empty()
{
    return true;
}
