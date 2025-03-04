/* 8/31/98 Mary Elaine Califf
 * a C++ linked list implementation of stacks
 */

// Modified:
//   8/20/2003 by Mary Elaine Califf
//      Changed to ANSI C++
// revised 12/25/20
// Brady Davidson and Mary Elaine Califf
//Implementation of a stack of integers

#include <iostream>
#include "Stack.h"

using namespace std;



//constructor
Stack::Stack()
{
  head = nullptr;
}

//destructor
Stack::~Stack(){
  clear();
}

//copy constructor
Stack::Stack(const Stack& other){
  head = nullptr;
  copy(other);
}

//assignment operator
Stack& Stack::operator=(const Stack& other){
   if(this != &other){
    clear();
    copy(other);
  }
  return *this;
}

//Clears the stack
void Stack::clear(){
  while(head != nullptr){
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

//copy constructor
void Stack::copy(const Stack& other){
  if(other.head == nullptr){
    head = nullptr;
  }
  else{
    head = new Node(other.head->data);
    Node* temp = head;
    Node* otherTemp = other.head->next;
    while(otherTemp != nullptr){
      temp->next = new Node(otherTemp->data);
      temp = temp->next;
      otherTemp = otherTemp->next;
    }
  }
}

// adds a new value to the stack
bool Stack::push(char newValue){
  Node* temp = new Node(newValue);
  temp->next = head;
  head = temp;
  return true;
}

//pops top item off of the stack
char Stack::pop(){
  if(head == nullptr){
    throw "Stack is empty";
  }
  char temp = head->data;
  Node* temp2 = head;
  head = head->next;
  delete temp2;
  return temp;
}
/*
bool Stack::push(char newValue)
{
  if (headIndex < MAX_STACK_SIZE - 1)
  {
    ++topIndex;
    stackArr[topIndex] = newValue;
    return true;
  }
  else
  {
    return false;
  }
}

char Stack::pop()
{
  // taking advantage of pre-increment so we don't have to save the value off to return it
  // in the case of an empty stack
  if (topIndex == -1)
  {
    throw "Stack is empty";
  }
  return stackArr[topIndex--];
}
*/
