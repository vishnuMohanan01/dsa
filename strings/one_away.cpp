/*
 * Suppose strings can have 3 operations on the `add char`, `remove char` and `replace char`.
 * Write a function to find if s2 is one operation away from s1.
*/

#include <iostream>
#include <string>

using namespace std;

bool isOneReplaceAway(string& s1, string& s2) {
  int different = false;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] != s2[i]) {
      if (different) return false;
      different = true;
    }
  }
  
  return true;
}

bool isOneAddAway(string& s1, string& s2) {
  int index1 = 0, index2 = 0;
  
  while (index1 < s1.size() && index2 < s2.size()) {
    if ((index2 - index1) > 1) return false;
    
    if (s1[index1] != s2[index2]) {
      index2++;
    } else {
      index1++;
      index2++;
    }
  }
  
  return true;
}

bool isOneOperationAway(string& s1, string& s2) {
  if (s1.size() == s2.size()) {
    return isOneReplaceAway(s1, s2);
  } else if (s1.size() < s2.size() && s2.size() - s1.size() == 1) {
    return isOneAddAway(s1, s2);
  } else if (s1.size() > s2.size() && s1.size() - s2.size() == 1) {
    return isOneAddAway(s2, s1);
  }
  
  return false;
}


int main() {
  string s1, s2;

  cout << "Enter s1: ";
  getline(cin, s1);
  
  cout << "Enter S2: ";
  getline(cin, s2);
  
  cout << isOneOperationAway(s1, s2);
  
  return 0;
}