/*
 * stackNode.h
 * Patrick Anderson psa5dg
 * 2/9/16
 */

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

class StackNode {
 public:
  StackNode();

 private:
  int value;
  StackNode *next;

  friend class Stack;
};

#endif
