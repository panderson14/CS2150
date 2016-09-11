//Patrick Anderson psa5dg
//topological.cpp
//4/25/16
//Lab 105

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <set>
using namespace std;


int main(int argc, char *argv[]) {

  string line;
  vector<string> left;
  vector<string> right;
  vector<string> final;
  vector<string> finishing;
  
  ifstream file(argv[1]);
  if (!file.is_open()) return false;

  while(getline(file, line)) {
    if (line == "0 0") break;
    left.push_back(line.substr(0, 6));
    right.push_back(line.substr(7, 6));
  }
  file.close();

  finishing = right;

  while(left.size() > 0) {
    vector<bool> checks;
    for(int i = 0; i<left.size(); i++) {
      bool check = false;
      for(int j = 0; j<right.size(); j++) {
	if (left[i] == right[j]) check = true;
      }
      checks.push_back(check);
    }


    for (int i = 0; i < checks.size(); i++) {
      if (!checks[i]) {
	final.push_back(left[i]);
	checks.erase(checks.begin()+i);
	left.erase(left.begin()+i);
	right.erase(right.begin()+i);
      }
    }
  }
  
  for(int i = 0; i < finishing.size(); i++) {
    bool b = false;
    for(int j = 0; j < final.size(); j++) {
         if(finishing[i] == final[j]) b = true;
       }
       if(!b) final.push_back(finishing[i]);
  }


  for(int i = 0; i < final.size()-1; i++) {
    string s = final[i];
    for(int j = i+1; j < final.size(); j++) {
      if(s == final[j]) {
	final.erase(final.begin()+j);
	j--;
      }
    }
  }
  
 for(int i = 0; i < final.size(); i++) {
    cout << final[i] << " ";
 }
 cout << endl;

  
  return 0;
}
