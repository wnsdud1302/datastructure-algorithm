#include<iostream>
#include"Stack.h"
using namespace std;

Stack::Stack(){
    ptr = 0;
    max = 0;
}

Stack::Stack(int n){
    ptr = 0;
    if((stk = new int[n]) == NULL){
        max = 0;
    }
    max = n;
}

int Stack::Push(int x){
    if(ptr >= max)
        return -1;
    stk[ptr++] = x;
    return 0;
}

int Stack::Pop(int *x){
    if(ptr == 0){
        return -1;
    }
    *x = stk[ptr--];
    return 0;
}

int Stack::Peek(int *x){
    if(ptr == 0)
        return -1;
    *x = stk[ptr - 1];
    return 0;
}

void Stack::clear(){
    ptr = 0;
}

int Stack::size(){
    return ptr;
}

int Stack::capacity(){
    return max;
}
bool Stack::isEmpty(){
    return ptr <= 0;
}

bool Stack::isFull(){
    return ptr >= max;
}

int Stack::Search(int x){
    int i = ptr - 1;
    while (i >= 0){
        if(stk[i] == x)
            return i;
        i--;
    }
    return -1;
}

void Stack::Print(){
    int i = 0;
    while( i < ptr){
        cout << stk[i] << " ";
        i++;
    }
    cout << endl;
}
