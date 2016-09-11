/*
 * stack.h
 * Patrick Anderson psa5dg
 * 2/9/16
 */

#ifndef STACK_H
#define STACK_H

#include "stackNode.h"
#include <cstdlib>
#include <iostream>
using namespace std;

class Stack {
 public:
  Stack();
  ~Stack();
  void push(int e);
  int top() const;
  void pop();
  bool empty() const;

 private:
  int count;
  StackNode *head;
};


#endif
