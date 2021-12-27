#include <iostream>
#include "MyStack.h"
using namespace std;

int main()
{
  MyStack *m, *s;
  m = new MyStack(5);
  s = new MyStack();
  int value;

  try
  {
    while (!s->isFull())
    {
      cout << "Enter an value to put in the stack" << endl;
      cin >> value;
      s->push(value);
    }
    s->push(32);
  }
  catch (std::overflow_error &e)
  {
    cout << e.what() << endl;
  }
  s->print();

  try
  {
    m->push(1);
    m->push(2);
    m->push(s->top());
    cout << "Stack m" << endl;
    m->print();
    m->pop();
    m->pop();
    m->pop();
    m->pop();
  }
  catch (std::underflow_error &e)
  {
    cout << e.what() << endl;
  }

  if (m->isEmpty())
  {
    cout << "Stack m is empty" << endl;
  }
  cout << "Stack m size is: " << m->size() << endl;
  s->clear();
}