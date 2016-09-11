//bitCounter.cpp
//Patrick Anderson psa5dg
//2/17/16

#include <iostream>
#include <cstdlib>
using namespace std;


int bitCounter(int i, int c);


int main(int argc, char *argv[]) {
  if (argv[1] == NULL) {
    cout << "Please enter a number." << endl;
    return 1;
  }

  cout << "The number of 1s in the binary of this number is " << bitCounter(atoi(argv[1]), 0) << endl;
  
  return 0;
}


int bitCounter(int i, int c) {
  if (i < 1) {
    return c;
  }

  if (i%2 != 0) c++;
  
  return bitCounter(i/2, c);
}
