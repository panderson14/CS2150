/*
 * stack.cpp
 * Patrick Anderson psa5dg
 * 2/9/16
 */

#include "stack.h"

Stack::Stack() {
  head = new StackNode;
  count = 0;
}

Stack::~Stack() {
  while(head->next != NULL) {
    this->pop();
  }
  count = 0;
  delete head;
}

void Stack::push(int e) {
  StackNode *newNode = new StackNode;
  newNode->value = e;
  newNode->next = head->next;
  head->next = newNode;
  count++;
}

int Stack::top() const {
  if (count == 0) {
    cout << endl;
    exit(-1);
  }
  
  return head->next->value;
}

void Stack::pop() {
  if (count == 0) exit(-1);
  
  StackNode *newNode = new StackNode;
  newNode->next = head->next;
  head->next = head->next->next;
  delete newNode->next;
  delete newNode;
  count--;
}

bool Stack::empty() const {
  if (count == 0) return true;
  return false;
}
