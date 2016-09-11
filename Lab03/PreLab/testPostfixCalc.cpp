/*
 * testPostfixCalc.cpp
 * Patrick Anderson psa5dg
 * 2/7/16
 */

#include <iostream>
#include <stack>
#include "postfixCalculator.h"


int main() {
  PostfixCalculator p;

  /*
  p.pushNum (1);
  p.pushNum (2);
  p.pushNum (3);
  p.pushNum (4);
  p.pushNum (5);
  p.add();
  p.add();
  p.add();
  p.add();
  */
  //expected output: 15

  /*
  p.pushNum (20);
  p.pushNum (10);
  p.subtract();
  p.pushNum (-3);
  p.pushNum (10);
  p.subtract();
  p.subtract();
  p.pushNum (2);
  p.subtract();
  */
  //expected output: 21

  /*
  p.pushNum (-1);
  p.pushNum (-2);
  p.pushNum (-5);
  p.pushNum (3);
  p.multiply();
  p.pushNum (2);
  p.pushNum (-2);
  p.multiply();
  p.multiply();
  p.multiply();
  p.multiply();
  */
  //expected output: 120

  /*
  p.pushNum (-1512);
  p.pushNum (-12);
  p.pushNum (-2);
  p.divide();
  p.divide();
  p.pushNum (-2);
  p.divide();
  p.pushNum (3);
  p.divide();
  */
  //expected output: 42

  /*
  p.pushNum (-1);
  p.negate();
  p.negate();
  p.negate();
  */
  //expected output: 1


  cout << "Result is: " << p.getTopValue() << endl;
  return 0;
}
