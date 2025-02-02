/*
 * Write a function to rotate an NxN matrix by 90deg in place.
*/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool rotate(vector<vector<int> >& matrix) {
  if (matrix.size() == 0 || matrix.size() != matrix[0].size()) return false;
  
  int n = matrix.size();
  for (int layer = 0; layer < n/2; layer++) {
    int last = n - layer - 1;
    
    for(int i = layer; i < last; i++) {
      int offset = i - layer;
      int top = matrix[layer][i]; // temp save top
      
      matrix[layer][i] = matrix[last - i][layer]; // move value at left to top
      matrix[last-i][layer] = matrix[last][last - offset]; // mave value at bottom to left
      matrix[last][last - offset] = matrix[i][last]; // move right to bottom
      matrix[i][last] = top; // move top to right
    }
  }
  
  return true;
}

int main() {
  int n;
  cout << "Enter the order: ";
  cin >> n;
  cin.ignore();
  
  if (n <= 0) {
    cout << "Enter an order greater than 0";
    return 1;
  }
  
  vector<vector<int> > matrix;
  
  for (int i = 0; i < n; i++) {
    string input;
    
    cout << endl << "Enter " << n << " elements: ";
    getline(cin, input);
    
    vector<int> row;
    istringstream inputStream(input);
    int num;
    while (inputStream >> num) {
      row.push_back(num);
    }
    
    matrix.push_back(row);
  }
  
  for (vector<int> row : matrix) {
    for (int n : row) {
      cout << n << ", ";
    }
    
    cout << endl;
  }
  
  cout << endl << "Rotating matrix:" << endl << endl;
  
  if (rotate(matrix)) {
    for (vector<int> row : matrix) {
      for (int n : row) {
        cout << n << ", ";
      }
      
      cout << endl;
    }
  }
  
  return 0;
}