/* 
Given a binary tree, design an algorithm which creates a linked list of all nodes at each depth 
(eg: If you have a tre with depth D, you'll have D linked lists).
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class LinkedListNode;
class LinkedList;
class TreeNode;
class Tree;

class LinkedListNode {
  public:
    TreeNode* item;
    LinkedListNode* next = NULL;
    
    LinkedListNode(TreeNode* newItem) : item(newItem) {}
    
    ~LinkedListNode() {
      delete next;
    }
};

class LinkedList {
  public:
    LinkedList() {
      head = new LinkedListNode(NULL);
      tail = head;
    }

    LinkedListNode* head;
    LinkedListNode* tail;
    
    void add(TreeNode* newItem) {
      tail->next = new LinkedListNode(newItem);
      tail = tail->next;
    }
    
    ~LinkedList() {
      delete head;
    }
};

class TreeNode {
  public:
    int number;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int num) : number(num) {}

    ~TreeNode() {
      delete left;
      delete right;
    }
};

class Tree {
  private:
    TreeNode* create(vector<int> arr, int start, int end) {
      if (start > end) return NULL;
      
      int mid = (start + end)/2;

      TreeNode* n = new TreeNode(arr[mid]);
      n->left = create(arr, start, mid - 1);
      n->right = create(arr, mid + 1, end);
      return n;
    }

  public:
    TreeNode* root;
    
    Tree(vector<int> arr) {
      root = create(arr, 0, arr.size() - 1);
    }
    
    ~Tree() {
      delete root;
    }
  
    // returns a vector of linked lists of all TreeNode* in the same level for each level in the tree
    void getLevelsList() {
      vector<LinkedList*> levelsList;
      
      preOrderTraverse(root, levelsList, 0);
      
      for (LinkedList* list : levelsList) {
        LinkedListNode* listNode = list->head->next;
        while(listNode != NULL) {
          cout << listNode->item->number;
          if (listNode->next != NULL) cout << "->";
          listNode = listNode->next;
        }
        
        cout << endl;
      }
      
      for (LinkedList* list : levelsList) {
        delete list;
      }
    }
    
    void preOrderTraverse(TreeNode* node, vector<LinkedList*>& levelsList, int level) {
      if (node == NULL) return;
      
      if (levelsList.size() <= level) {
        levelsList.resize(level + 1, NULL);
      }
      
      if (levelsList[level] == NULL) levelsList[level] = new LinkedList();
      
      levelsList[level]->add(node);
      preOrderTraverse(node->left, levelsList, level + 1);
      preOrderTraverse(node->right, levelsList, level + 1);
    }
};

int main() {
  string input;
  
  cout << "Enter tree elements (space-separated):" << endl;
  getline(cin, input);
  
  istringstream input_stream(input);
  int number;
  vector<int> input_numbers;

  while(input_stream >> number) {
    input_numbers.push_back(number);
  }
  
  Tree tree(input_numbers);
  tree.getLevelsList();

  return 0;
}