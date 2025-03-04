/* 8/31/98 Mary Elaine Califf
 * a C++ array implementation of stacks
 *
 * Revised 12/25/2020
 */
 // Brady Davidson and Mary Elaine Califf
 //Header file for a stack of integers

#ifndef STACK_H
#define STACK_H

class Stack
{

public:


  Stack(); // constructor
  Stack(const Stack& other); // copy constructor
  Stack& operator=(const Stack& other); // assignment operator
  ~Stack();// destructor

  // add a new value to the stack
  // fails and return false if the stack is full
  bool push(char newValue);

  // pops top item off of the stack
  // Precondition: stack must not be empty
  char pop();

  // return item at the top of the stack without removing it
  // Precondition: stack must not be empty
  char top() {return head->data;};

  // return true if the stack is empty
  bool isEmpty() { return (head == nullptr); }

// clear the stack
  void clear();

// copy constructor
  void copy(const Stack& other);

private:
  
  //static const int MAX_STACK_SIZE = 500;
  //char stackArr[MAX_STACK_SIZE]; // note can only handle 100 items
  //int topIndex;


// node struct
  struct Node{
  char data;
  Node* next;
  Node (char value) : data(value), next(nullptr) {};
  };
  Node* head;


};

#endif
