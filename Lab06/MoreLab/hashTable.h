// hashTable.h
// Patrick Anderson psa5dg
// 3/14/16
// Lab 105

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>
#include <iostream>
#include <tgmath.h>
using namespace std;

class HashTable {
 public:
  HashTable(int size);
  void insert(string s);
  bool find(string s);

 private:
  unsigned int hash(string s);
  vector<string> v;
};

#endif
