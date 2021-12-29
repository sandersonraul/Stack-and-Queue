#include "MyQueue.h"

MyQueue::MyQueue(int size)
{
  f = -1;
  r = -1;
  capacity = size;
  vet = new int[capacity];
}

MyQueue::MyQueue()
{
  f = -1;
  r = -1;
  capacity = 10;
  vet = new int[capacity];
}

bool MyQueue::isEmpty()
{
  if (f == -1 && r == -1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool MyQueue::isFull()
{
  if (f == 0 && r == capacity - 1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int MyQueue::size()
{
  return this->capacity;
}

int MyQueue::front()
{
  return vet[f];
}

int MyQueue::back()
{
  return vet[r];
}

void MyQueue::enqueue(int element)
{
  if ((f == 0 && r == capacity - 1) || (r == (f - 1) % (capacity - 1)))
  {
    std::__throw_overflow_error("Queue Overflow");
  }
  else if (f == -1)
  {
    f = r = 0;
    vet[r] = element;
  }

  else if (r == capacity - 1 && f != 0)
  {
    r = 0;
    vet[r] = element;
  }

  else
  {
    r++;
    vet[r] = element;
  }
}

int MyQueue::dequeue()
{
  if (f != -1)
  {
    int recovered_value = vet[f];
    if (f == r)
    {
      f = r = -1;
    }
    else
    {
      f = (f % capacity) + 1;
    }
  }
  else
  {
    std::__throw_underflow_error("Queue Underflow");
  }

  return vet[f];
}

void MyQueue::clear()
{
  if (isEmpty())
  {
    std::cout << "Nothing to clear";
  }
  else
  {
    while (!isEmpty())
    {
      dequeue();
    }
  }
}

void MyQueue::print(std::ostream &cout) const
{
  if (f == -1)
  {
    cout << "Queue is empty ";
  }

  if (r >= f)
  {
    for (int i = f; i <= r; i++)
      cout << vet[i] << " | ";
  }
  else
  {
    for (int i = f; i < capacity; i++)
      cout << vet[i] << " | ";

    for (int i = 0; i <= r; i++)
      cout << vet[i] << " | ";
  }
}
