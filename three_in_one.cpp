/* 
Use a single array to implement 3 stacks.

Approach 1 [FixedMultiStack]: Divide an array into 3 fixed sized stacks. The downside is - a stack can run out of space even if other 2 stacks are nearly empty.
*/

#include <iostream>
#include <exception>

using namespace std;

class FixedMultiStack {
  private:
    int numberOfStacks = 3;
    int stackCapacity;
    int* values;
    int* sizes;
  
  public:
    class FullStackException : public std::exception {
      public:
        const char* what() const throw() {
            return "Stack is full. Cannot push more elements.";
        }
    };
  
    class EmptyStackException : public std::exception {
      public:
        const char* what() const throw() {
            return "Stack is empty. Cannot pop or peek.";
        }
    };
  
    FixedMultiStack(int stackSize) {
      stackCapacity = stackSize;
      values = new int[numberOfStacks * stackSize];
      sizes = new int[numberOfStacks];
    }

    void push(int stackNum, int value) {
      if (isFull(stackNum)) throw FullStackException();
      
      sizes[stackNum]++;
      values[indexOfTop(stackNum)] = value;
    }
    
    int pop(int stackNum) {
      if (isEmpty(stackNum)) throw EmptyStackException();
      
      int topIndex = indexOfTop(stackNum);
      int value = values[topIndex];
      values[topIndex] = 0;
      sizes[stackNum]--;
      
      return value;
    }
    
    int peek(int stackNum) {
      if (sizes[stackNum] == 0) throw EmptyStackException();
      
      return values[indexOfTop(stackNum)];
    }
    
    bool isEmpty(int stackNum) {
      return sizes[stackNum] == 0;
    }
    
    bool isFull(int stackNum) {
      return sizes[stackNum] == stackCapacity;
    }
    
    int indexOfTop(int stackNum) {
      int offset = stackNum * stackCapacity;
      return offset + (sizes[stackNum] - 1);
    }
    
    void peekAll() {
      for(int i = 0; i < numberOfStacks; i++) {
        cout << "Stack Number[" << i << "]: " << peek(i) << endl;
      }
    }
};

int main() {
  FixedMultiStack fixedMultiStack(2);
  
  fixedMultiStack.push(0, 10);
  fixedMultiStack.push(0, 20);
  
  fixedMultiStack.push(1, 100);
  fixedMultiStack.push(1, 200);
  
  fixedMultiStack.push(2, 1000);
  fixedMultiStack.push(2, 2000);
  
  fixedMultiStack.peekAll();
  
  cout << fixedMultiStack.pop(0) << endl;
  cout << fixedMultiStack.pop(1) << endl;
  cout << fixedMultiStack.pop(2) << endl;
  
  fixedMultiStack.peekAll();
}
