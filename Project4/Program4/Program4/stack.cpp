#include "stack.h"

Stack::Stack(int size)
{
    top=-1;
    length = size;
    p = new StackNode[length];
}

Stack::~Stack()
{
    delete p;
}

int Stack::getCost(StackNode& n)
{
    return n.cost;
}

string Stack::getCityName(StackNode& n)
{
    return n.cityName;
}

Stack::StackNode Stack::pop()
{
    if(p == 0 || top == -1)
    {
        cout << "Stack empty." << endl;
        cout << "Will cause out of bounds now." << endl;
    }
    StackNode temp = p[top];
//    top--;
//    length--;
    return temp;
}

bool Stack::isEmpty()
{
    if(p==0 || top == -1)
    {
        return true;
    }
    else
        return false;
}

string Stack::popOffName()
{
    StackNode s = pop();

    return s.cityName;
}

int Stack::popOffCost()
{
    StackNode c = pop();
    top--;//moved these from pop() to here so I could pop off while keeping StackNode private
    length--;//assuming I will popOffName() then popOffCost()
    return c.cost;
}

void Stack::push(int cost, string &cityName)
{
    StackNode flight;
    flight.cost = cost;
    flight.cityName = cityName;
    if(top == length-1)
    {
        cout << "Stack is full." << endl;
    }
    else
    {
        top++;
        p[top] = flight;
    }
}

void Stack::push(string& cityName)
{
    StackNode originCity;
    originCity.cityName = cityName;
    if(top == length-1)
    {
        cout << "Stack is full." << endl;
    }
    else
    {
        top++;
        p[top] = originCity;
    }
}

int Stack::getLength()
{
    return length;
}

void Stack::setLength(int len)
{
    length = len;
}

int Stack::getTop()
{
    return top;
}

void Stack::setTop(int t)
{
    this->top = t;
}
