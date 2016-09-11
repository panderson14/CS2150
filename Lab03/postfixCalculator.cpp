/*
 * postfixCalculator.cpp
 * Patrick Anderson psa5dg
 * 2/7/16
 */

#include "postfixCalculator.h"


PostfixCalculator::PostfixCalculator() {

}

PostfixCalculator::~PostfixCalculator() {

}

void PostfixCalculator::pushNum(int e) {
  s.push(e);
}

int PostfixCalculator::getTopValue() const {
  return s.top();
}

void PostfixCalculator::add() {
  int x = s.top();
  s.pop();
  int y = s.top();
  s.pop();
  s.push(y+x);
}

void PostfixCalculator::subtract() {
  int x = s.top();
  s.pop();
  int y = s.top();
  s.pop();
  s.push(y-x);
}

void PostfixCalculator::multiply() {
  int x = s.top();
  s.pop();
  int y = s.top();
  s.pop();
  s.push(y*x);  
}

void PostfixCalculator::divide() {
  int x = s.top();
  s.pop();
  int y = s.top();
  s.pop();
  s.push(y/x);  
}

void PostfixCalculator::negate() {
  int x = s.top();
  s.pop();
  s.push(-x);  
}
