#include "MyStack.h"

MyStack::MyStack(int size)
{
  topo = -1;
  capacity = size;
  vet = new int[capacity];
}

MyStack::MyStack()
{
  topo = -1;
  capacity = 10;
  vet = new int[capacity];
}

bool MyStack::isEmpty()
{
  if (topo == -1)
  {
    return true;
  }
  else
  {
    return 0;
  }
}

bool MyStack::isFull()
{
  if (topo == capacity - 1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int MyStack::size()
{
  return this->capacity;
}

int MyStack::top()
{
  return vet[topo];
}

void MyStack::push(int data)
{
  if (isFull())
  {
    std::__throw_overflow_error("MyStack OverFlow");
  }
  else
  {
    vet[++topo] = data;
  }
}

void MyStack::pop()
{
  if (isEmpty())
  {
    std::__throw_underflow_error("MyStack Underflow");
  }
  else
  {
    int recovered_value = vet[--topo];
  }
}

void MyStack::clear()
{
  if (isEmpty())
  {
    std::cout << "Nothing to clear";
  }
  else
  {
    for (int i = topo; i > 0; i--)
    {
      int recoverd_value = vet[--topo];
    }
  }
}

void MyStack::print(std::ostream &cout) const
{
  for (int i = topo; i > -1; i--)
  {
    cout << vet[i] << std::endl;
  }
}
