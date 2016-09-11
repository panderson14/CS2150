// Example time of my program: 0.218105 seconds for the 4x7
// Big-Theta == theta(n^4)
// wordPuzzle.cpp
// Patrick Anderson psa5dg
// 3/14/16
// Lab 105

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "hashTable.h"
#include "timer.h"
#include <sstream>
#define MAXROWS 500
#define MAXCOLS 500
using namespace std;

char table[MAXROWS][MAXCOLS];
bool readInTable (string filename, int &rows, int &cols);
char* getWordInTable (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols);


bool checkprime(unsigned int p);
int getNextPrime (unsigned int n);



int main(int argc, char *argv[]) {
  string line;
  int i = 0;
  int rows = 0;
  int cols = 0;
  vector<string> out = vector<string>(30000);
  string output = " ";
  
  ifstream file(argv[1]);
  if (!file.is_open()) return false;

  while(getline(file, line)) {
    i++;
  }
  file.close();
  i = i*5;
  i = getNextPrime((unsigned int)i);

  HashTable h(i);

  ifstream file1(argv[1]);
  while(getline(file1, line)) {
    h.insert(line);
  }
  string str(argv[2]);
  string compare = " ";
  int wordCount = 0;
  readInTable(str, rows, cols);
  timer t;
  t.start();
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      for (int d = 0; d < 8; d++) {
	for (int l = 3; l <= 22; l++) {
	  string word(getWordInTable(r, c, d, l, rows, cols));
	  if (word.length() >= 3) {
	    if(h.find(word)) {
	      if (compare.compare(word) != 0) {
		string dir = " ";
		switch (d) {
		case 0:
		  dir = "N";
		  break;
		case 1:
		  dir = "NE";
		  break;
		case 2:
		  dir = "E";
		  break;
		case 3:
		  dir = "SE";
		  break;
		case 4:
		  dir = "S";
		  break;
		case 5:
		  dir = "SW";
		  break;
		case 6:
		  dir = "W";
		  break;
		case 7:
		  dir = "NW";
		  break;  
		}
		stringstream ss;
		ss << dir << " (" << r << ", " << c << "):     " << word;
		output = ss.str();
		ss.flush();
	        out.push_back(output);
		wordCount++;
	      }
	    }
	  }
	  compare = word;
	}
      }
    }
  }
  t.stop();
  for (int i = 0; i < out.size(); i++) {
    if (out[i].size()>1) cout << out[i] << endl;
  }
  cout << wordCount << " words found " << endl;
  cout << "Found all words in " << t.getTime() << " seconds" << endl;
  //int seconds = (int)(t.getTime())*1000;
  //cout << seconds;
  return 0;
}

bool readInTable (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // table[][] array.  In the process, we'll print the table to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            table[r][c] = line[pos++];
            //cout << table[r][c];
        }
        //cout << endl;
    }
    // return success!
    return true;
}


char* getWordInTable (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the table
        output[pos++] = table[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes table[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}

bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
