#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <iostream>

class MyQueue
{
public:
  MyQueue(int size);
  MyQueue();

  bool isEmpty();
  bool isFull();
  int size();
  int front();
  int back();
  void enqueue(int element);
  int dequeue();
  void clear();
  void print(std::ostream &cout = std::cout) const;

private:
  int f, r;
  int capacity;
  int *vet;
};
#endif