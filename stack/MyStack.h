#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>

class MyStack
{
public:
  MyStack(int size);
  MyStack();

  bool isEmpty();
  bool isFull();
  int size();
  int top();
  void push(int element);
  int pop();
  void clear();
  void print(std::ostream &cout = std::cout) const;

private:
  int topo;
  int capacity;
  int *vet;
};
#endif
