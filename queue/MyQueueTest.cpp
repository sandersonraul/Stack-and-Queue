#include <iostream>
#include "MyQueue.h"
using namespace std;

int main()
{

  MyQueue *m, *s;
  m = new MyQueue(5);
  s = new MyQueue();
  int value;

  try
  {
    while (!s->isFull())
    {
      cout << "Enter an value to put in the Queue" << endl;
      cin >> value;
      s->enqueue(value);
    }
    s->enqueue(32);
  }
  catch (std::overflow_error &e)
  {
    cout << e.what() << endl;
  }
  s->print();
  if (s->isFull())
  {
    cout << "\nQueue is full\n";
  }

  try
  {
    m->enqueue(30);
    m->enqueue(2);
    m->enqueue(s->front());
    m->enqueue(s->back());
    cout << "\nQueue m" << endl;
    m->print();
    m->dequeue();
    m->dequeue();
    m->dequeue();
    m->dequeue();
    m->dequeue();
  }
  catch (std::underflow_error &e)
  {
    cout << e.what() << endl;
  }

  if (m->isEmpty())
  {
    cout << "Queue m is empty" << endl;
  }
  cout << "Queue m size is: " << m->size() << endl;
  s->clear();
  s->print();
}