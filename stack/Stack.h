#ifndef STACK_H
#define STACK_H

using namespace std;

class Stack
{
    public:
    Stack();
    Stack(int max);
    int push(int x);
    int pop(int *x);
    int peek(int *x);
    void clear();
    int capacity();
    bool isEmpty();
    bool isull();
    int search(int x);
    void print();
    void terminate();

    private:
    int ptr;
    int max;
    int *stk;

};
#endif
