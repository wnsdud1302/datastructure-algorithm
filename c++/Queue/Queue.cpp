#include<iostream>
#include"queue.h"
using namespace std;



queue::queue(int n){
    front = rear = num = max = 0;
    if((que = new int[n]) == NULL)
        cout << "큐 생성에 실패하였습니다" << endl;
    max = n;
}

void queue::Enque(int x){
    if (num >= max)
        cout << "인큐에 실패하였습니다." << endl;
    num++;
    que[rear++] = x;
    if(rear == max)
        rear = 0;

}

void queue::Deque(int *x){
    if(num <= 0)
        cout << "디큐에 실패하였습니다." << endl;
    num--;
    *x = que[front++];
    if(front == max)
        front = 0;

}

void queue::Peek(int *x){
    *x = que[front + 1];
}

void queue::Clear(){
    front = rear = num = 0;
}

int queue::Capacity(){
    return max;
}

int queue::Size(){
    return num;
}

bool queue::IsEmpty(){
    return num <= 0;
}

bool queue::IsFull(){
    return num >= max;
}

void queue::Search(int *x, int idx){
    for(int i = 0; i < num; i++){
        if(que[idx = (i+front) % max] == *x)
            break;
    }
}
void queue::Print(){
    int idx;
    for(int i = 0; i < num; i++){
        cout << que[(i+front) % max];
    }
    cout << endl;
}

queue::~queue(){
    if(que != NULL)
        delete que;
    max = num = front = rear = 0;
}
