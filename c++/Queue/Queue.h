#ifndef QUEUE_H
#define QUEUE_H

class queue
{
private:
    int front;
    int rear;
    int *que;
    int num;
    int max;
public:
    queue();
    queue(int max);
    void Enque(int x);
    void Deque(int *x);
    void Peek(int *x);
    void Clear();
    int Capacity();
    int Size();
    bool IsEmpty();
    bool IsFull();
    void Search(int *x);
    void Print();
    ~queue();
};

#endif
