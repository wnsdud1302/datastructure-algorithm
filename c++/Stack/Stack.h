#ifndef STACK_H
#define STACK_H

class Stack{
public:
    Stack();
    Stack(int n);
    int Push(int x);
    int Pop(int *x);
    int Peek(int *x);
    void clear();
    int capacity();
    int size();
    bool isEmpty();
    bool isFull();
    int Search(int x);
    void Print();
    friend ostream& operator <<(ostream& outputStream, const Stack& str);
    void Terminate();
private:
    int max;
    int ptr;
    int *stk;
};
#endif
