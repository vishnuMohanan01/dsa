/*
 * Given a string, write a function to check if the given string is a permutation of a palindrome.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isPalindromePermutation(string& str) {
  unordered_map<char, int> charCounts;
  int oddCounter = 0;
  
  for (char c : str) {
    if (charCounts.find(c) == charCounts.end()) {
      charCounts[c] = 1;
      oddCounter++;
    } else {
      charCounts[c]++;
      
      if (charCounts[c] % 2 == 0) {
      oddCounter--;
      } else {
        oddCounter++;
      }
    }
  }
  
  if (str.size() % 2 == 0 && oddCounter == 0 || str.size() % 2 == 1 && oddCounter == 1) return true;
  
  return false;
}

int main() {
  string str;

  cout << "Enter the string: ";
  getline(cin, str);
  
  cout << "This is a permuation of a palindrome ? " << isPalindromePermutation(str) << endl;
  
  return 0;
}