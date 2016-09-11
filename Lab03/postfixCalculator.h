/*
 * postfixCalculator.h
 * Patrick Anderson psa5dg
 * 2/7/16
 */

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "stack.h"
using namespace std;

class PostfixCalculator {
 public:
  PostfixCalculator();
  ~PostfixCalculator();
  void pushNum(int e);
  int getTopValue() const;
			 
  void add();
  void subtract();
  void multiply();
  void divide();
  void negate();

			 
 private:
  Stack s;
};



#endif
