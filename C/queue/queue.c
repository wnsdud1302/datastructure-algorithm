#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

int Initialize(Queue *q, int max){
    q->num = q->front = q->rear = 0;
    if((q->que = calloc(max, sizeof(int))) == NULL){
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;

}
int Enque(Queue *q, int x){
    if(q->num == q->max)
        return -1;
    else
    {
        q->num++;
        q->que[q->rear++] = x;
        if(q->rear == q->max)
            q->rear = 0;
        return 0;
    }
    
}
int Deque(Queue *q, int *x){
    if(q->num <= 0)
        return -1;
    else
    {
        q->num--;
        *x = q->que[q->front++];
        if(q->front == q->max)
            q->front = 0;
        return 0;
    }
    
}
int Peek(const Queue *q, int *x){
    if(q->num <= 0)
        return -1;
    *x = q->que[q->front];

}
void Clear(Queue *q){
    q->num = q->front = q->rear = 0;
}
int Capacity(const Queue *q){
    return q->max;
}
int size(const Queue *q){
    return q->num;
}
int IsEmpty(const Queue *q){
    return q->num <= 0;
}
int IsFull(const Queue *q){
    return q->num >= q->max;

}
int Search(const Queue *q, int x){
    int idx;
    for(int i = 0; i < q->num; i++){
        if(q->que[idx = (i + q->front) % q->max] == x)
            return idx;
    }
}
void Print(const Queue *q){
    for (int i = 0; i < q->num; i++)
    {
        printf("%d ", q->que[(i + q->front) % q->max]);
    
    }
    putchar('\n');
    
}
void Terminate(Queue *q){
    if(q->que != NULL)
        free(q->que);
    q->max = q->num = q->front = q->rear = 0;
}
