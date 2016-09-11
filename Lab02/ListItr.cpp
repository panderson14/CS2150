//Patrick Anderson psa5dg 2/4/16

#include "ListItr.h"

ListItr::ListItr() {
  current = NULL;
}


ListItr::ListItr(ListNode* theNode) {
  current = theNode;
}


bool ListItr::isPastEnd() const {
  if (current->next == NULL) return true;
  return false;
}

bool ListItr::isPastBeginning() const {
  if (current->previous == NULL) return true; 
  return false;
}

void ListItr::moveForward() {
  if (current->next == NULL) return;
  current = current->next;
}

void ListItr::moveBackward() {
  if (current->previous == NULL) return;
  current = current->previous;
}

int ListItr::retrieve() const {
  return current->value;
}
