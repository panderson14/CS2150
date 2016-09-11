//Patrick Anderson psa5dg 2/4/16

#include "List.h"

List::List() {
  head = new ListNode;
  tail = new ListNode;
  head->next=tail;
  tail->previous=head;
  count=0;
}


List::List(const List& source) {
  head=new ListNode;
  tail=new ListNode;
  head->next=tail;
  tail->previous=head;
  count=0;
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {       // deep copy of the list
      insertAtTail(iter.retrieve());
      iter.moveForward();
  }
}


List::~List() {
  makeEmpty();
  delete head;
  delete tail;
}


List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const {
  if (count == 0) return true;
  return false;
}

void List::makeEmpty() {
  ListItr iter(head->next);
  head->next = tail;
  while (!iter.isPastEnd()) {
    iter.moveForward();
    delete iter.current->previous;
  }
  iter.current->previous = head;
  count = 0;
}

ListItr List::first() {
  ListItr iter(head->next);
  return iter;
}

ListItr List::last() {
  ListItr iter(tail->previous);
  return iter;
}

void List::insertAfter(int x, ListItr position) {
  if (position.current == tail) {
    insertBefore(x, position);
    position.moveBackward();
    return;
  }
  ListNode *newNode = new ListNode;
  newNode->value = x;
  newNode->previous = position.current;
  newNode->next = position.current->next;
  position.current->next->previous = newNode;
  position.current->next = newNode;
  count++;
}

void List::insertBefore(int x, ListItr position) {
    if (position.current == head) {
    insertAfter(x, position);
    position.moveForward();
    return;
  }
  ListNode *newNode = new ListNode;
  newNode->value = x;
  newNode->next = position.current;
  newNode->previous = position.current->previous;
  position.current->previous->next = newNode;
  position.current->previous = newNode;
  count++;
}

void List::insertAtTail(int x) {
  ListNode *newNode = new ListNode;
  ListItr position(tail->previous);
  newNode->value = x;
  newNode->next = tail;
  newNode->previous = position.current;
  position.current->next = newNode;
  tail->previous = newNode;
  count++;
}

void List::remove(int x) {
  ListItr iter(head->next);
  while (!iter.isPastEnd()) {
    if(iter.retrieve() == x) {
      iter.current->previous->next = iter.current->next;
      iter.current->next->previous = iter.current->previous;
      delete iter.current;
      count--;
      break;
    }
    else iter.moveForward();
  }
}

ListItr List::find(int x) {
   ListItr iter(head->next);
   while (!iter.isPastEnd()) {
     if(iter.retrieve() == x) return iter;
     iter.moveForward();
  }
   return iter;
}

int List::size() const {
  return count;
}

void printList(List& source, bool direction) {
  if (direction) {
    ListItr iter = source.first();
   while (!iter.isPastEnd()) {
     cout << endl << iter.retrieve() << " ";
     iter.moveForward();
   }
  }
  
   else {
     ListItr iter = source.last();
    while (!iter.isPastBeginning()) {
      cout << endl << iter.retrieve() << " ";
      iter.moveBackward();
    }
  }
  
}
