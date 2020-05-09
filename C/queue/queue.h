#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue
{
    int max;
    int num;
    int front;
    int rear;
    int *que;
} Queue;

int Initialize(Queue *q, int max);
int Enque(Queue *q, int x);
int Deque(Queue *q, int *x);
int Peek(const Queue *q, int *x);
void Clear(Queue *q);
int Capacity(const Queue *q);
int size(const Queue *q);
int IsEmpty(const Queue *q);
int IsFull(const Queue *q);
int Search(const Queue *q, int x);
void Print(const Queue *q);
void Terminate(Queue *q);

#endif
