/*
 * Given a URL convert spaces into %20 and trim trailing spaces.
*/

#include <iostream>

using namespace std;

const int MAX_URL_LENGTH = 2048;

char* urlify(char str[]) {
  int space_count = 0;
  int i = 0;
  
  while (str[i]) {
    if (str[i] == ' ') space_count++;
    i++;
  }
  
  while (str[i - 1] == ' ') {
    space_count--;
    i--;
  }
  
  int total_length = i + 1 + space_count * 2;
  int j = total_length - 1;
  
  str[j--] = '\0';
  
  for (int k = i - 1; k >= 0; k--) {
    if (str[k] == ' ') {
      str[j] = '0';
      str[j - 1] = '2';
      str[j - 2] = '%';
      j = j - 3;
    } else {
      str[j] = str[k];
      j--;
    }
  }

  return str;
}

int main() {
  char str[MAX_URL_LENGTH];
  
  cout << "Enter Human readable url:";
  cin.getline(str, MAX_URL_LENGTH);
  
  cout << "Encoded Url: " << urlify(str);
}