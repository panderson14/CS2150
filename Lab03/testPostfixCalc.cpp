/*
 * testPostfixCalc.cpp
 * Patrick Anderson psa5dg
 * 2/7/16
 */

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "postfixCalculator.h"


int main() {
  PostfixCalculator p;

  while (cin.good()) {
      char *cstr = new char[256];
      cin >> cstr;
      if (isdigit(cstr[0]) != 0 || strlen(cstr) > 1) {
	int i = atoi(cstr);
	p.pushNum (i);
      }
      else {
	if (cstr[0] == '+') p.add();
	if (cstr[0] == '-') p.subtract();
	if (cstr[0] == '*') p.multiply();
	if (cstr[0] == '/') p.divide();
	if (cstr[0] == '~') p.negate();
      }
  }

  cout << "Result is: " << p.getTopValue() << endl;
  return 0;
}

  /*
  p.pushNum (6);
  p.pushNum (7);
  p.pushNum (2);
  p.pushNum (4);
  p.add();
  p.subtract();
  p.divide();
  */
  //expected output: 6

  /*
  p.pushNum (9);
  p.pushNum (4);
  p.pushNum (6);
  p.pushNum (4);
  p.multiply();
  p.negate();
  p.add();
  p.subtract();
  */
  //expected output: 29

  /*
  p.pushNum (23);
  p.pushNum (23);
  p.pushNum (2);
  p.divide();
  p.pushNum (2);
  p.multiply();
  p.subtract();
  */
  //expected output: 1

  /*
  p.pushNum (4);
  p.pushNum (0);
  p.add();
  p.pushNum (0);
  p.multiply();
  p.pushNum (1);
  p.add();
  p.negate();
  */
  //expected output: -1

  /*
  p.pushNum (-1);
  p.pushNum (-1);
  p.subtract();
  p.negate();
  p.negate();
  p.negate();
  */
  //expected output: 0
