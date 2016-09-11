//prelab4.cpp
//Patrick Anderson psa5dg
//2/17/16

#include <iostream>
#include <climits>
using namespace std;

void sizeOfTest();
void outputBinary(unsigned int x);
void overflow();



int main() {
  //sizeOfTest();
  //outputBinary(1000000);
  //overflow();
  return 0;
}



void sizeOfTest() {
  cout << "The size of an int is " << sizeof(int) << " bytes." << endl;
  cout << "The size of an unsigned int is " << sizeof(unsigned int) << " bytes." << endl;
  cout << "The size of a float is " << sizeof(float) << " bytes." << endl;
  cout << "The size of a double is " << sizeof(double) << " bytes." << endl;
  cout << "The size of a char is " << sizeof(char) << " byte." << endl;
  cout << "The size of a bool is " << sizeof(bool) << " byte." << endl;
  cout << "The size of an int pointer is " << sizeof(int*) << " bytes." << endl;
  cout << "The size of a char pointer is " << sizeof(char*) << " bytes." << endl;
  cout << "The size of a double pointer is " << sizeof(double*) << " bytes." << endl;
}


void outputBinary(unsigned int x) {
  unsigned int r = 0;
  int binary[32];
  int count = 31;

  for (int j = 0; j < 32; j++) {
    binary[j] = 0;
  }
  
  while(x > 0) {
    r = x%2;
    x = x/2;
    binary[count] = r;
    count--;
  }

  for (int k = 0; k < 32; k++) {
    cout << binary[k];
    if (k == 3 || k == 7 || k == 11 || k == 15 || k == 19 || k == 23 || k == 27) {
      cout << " ";
    }
  }
  cout << endl;
  
}


void overflow() {
  unsigned int i = UINT_MAX;
  cout << "Before: " << i << endl;
  outputBinary(i);
  i++;
  cout << "After: " << i << endl;
  outputBinary(i);
  cout << "C++ uses twos complement, meaning that when the highest number an int can hold is incremented by one, it drops down to the lowest value. Since unsigned ints dont hold negative numbers, this lowest value is 0. Normally, the leftmost bit would be a 1 if the number is negative, but unsigned ints simply use this bit to store larger positive values." << endl;
}
