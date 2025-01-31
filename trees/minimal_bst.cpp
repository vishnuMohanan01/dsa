/* 
Given a sorted (increasing) array with unique integer elements, write an algorithm to create to create a binary
search tree with minimal height.
*/

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Node {
  public:
    int number;
    Node* left;
    Node* right;

    Node(int num) : number(num) {}
    
    ~Node() {
      delete left;
      delete right;
    }
};

class MinimalBST {
  public:
    Node* root;

    MinimalBST(vector<int> arr) {
      root = createMinimalBST(arr, 0, arr.size() - 1);
    }

    ~MinimalBST() {
      delete root;
    }
    
    void printTree() {
      cout << "In-Order traversal:" << endl;
      inOrderTraversal(root);
      
      cout << endl << "Pre-Order traversal:" << endl;
      preOrderTraversal(root);
      
      cout << endl << "Post-Order traversal:" << endl;
      postOrderTraversal(root);
    }
    
  private:
    void inOrderTraversal(Node* n) {
      if (n == NULL) return;

      inOrderTraversal(n->left);
      cout << n->number << " -> ";
      inOrderTraversal(n->right);
    };

    void preOrderTraversal(Node* n) {
      if (n == NULL) return;

      cout << n->number << " -> ";
      preOrderTraversal(n->left);
      preOrderTraversal(n->right);
    };

    void postOrderTraversal(Node* n) {
      if (n == NULL) return;

      postOrderTraversal(n->left);
      postOrderTraversal(n->right);
      cout << n->number << " -> ";
    };

    Node* createMinimalBST(vector<int> arr, int start, int end) {
      if (start > end) return NULL;

      int mid = (start + end)/2;
      Node* node = new Node(arr[mid]);
      node->left = createMinimalBST(arr, start, mid - 1);
      node->right = createMinimalBST(arr, mid+1, end);

      return node;
    }
};

int main() {
  string input;
  vector<int> arr;

  cout << "Enter elements (space-separated) in ascending order:" << endl;
  getline(cin, input);

  istringstream inputStream(input);
  int number;
  while (inputStream >> number) {
    arr.push_back(number);
  }

  MinimalBST minimalBst(arr);

  cout << "Minimal BST:" << endl;
  minimalBst.printTree();

  return 0;
}
