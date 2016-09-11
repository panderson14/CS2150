// hashTable.cpp
// Patrick Anderson psa5dg
// 3/14/16
// Lab 105

#include "hashTable.h"

HashTable::HashTable(int size) {
  v = vector<string>(size);
}

void HashTable::insert(string s) {
  unsigned int location = hash(s);
  int x = 1;
  while (v[location].length() != 0) {
    location = (location+(x*x))%v.size();
    x++;
  }
  v[location] = s;
}

unsigned int HashTable::hash(string s) {
  unsigned int retVal = 0;
  for (int i = 0; i < s.size(); i++) {
    retVal += ((unsigned int)s.at(i))*pow(7, i);
  }
  retVal = retVal%v.size();
  return retVal;
}

bool HashTable::find(string s) {
  unsigned int location = hash(s);
  int x = 1;
  while (v[location].length() != 0) {
    if (v[location].compare(s) == 0) {
      return true;
    }
    location = (location+(x*x))%v.size();
    x++;
  }
  return false;
}
