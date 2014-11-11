#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
using namespace std;

class Stack//Stack code adapted from http://simplestcodings.blogspot.com/2010/07/stack-implementation-in-c.html
{
private:
    struct StackNode
    {
        string cityName;
        int cost;
    };

public:
    Stack(int size);
    ~Stack();
    void push(int cost, string& cityName);
    void push(string& cityName);
    string popOffName();
    int popOffCost();
    int getLength();
    void setLength(int len);
    int getTop();
    void setTop(int t);
    int getCost(StackNode &n);
    string getCityName(StackNode& n);
    bool isEmpty();

private:
    int top;
    int length;
    StackNode* p;
    StackNode pop();

};

#endif // STACK_H
