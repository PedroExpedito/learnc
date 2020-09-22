/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: oliveira
 *
 * Created on 21 de setembro de 2020, 12:22
 */

#include <cstdlib>
#include "Stack.hpp"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

    Stack<double> myStack(1);

    myStack.push(10);
    myStack.pop();

    return 0;
}

