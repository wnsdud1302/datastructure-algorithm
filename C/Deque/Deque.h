#ifndef DEQUE_H
#define DEQUE_H
#include<stdio.h>
#include<stdlib.h>
#include"Double_Linked_list.h"

typedef struct Deque
{
    int n;
    list *l;
} Deque;

void Dinitialize(Deque *d){
    d->n = 0;
    Initialize(d->l);
}

int size(const Deque *d){
    return d->n;
}

int isEmpty(const Deque *d){
    return IsEmpty(d->l);
}

int data(const Deque *d, int k){
    return Data(d->l, k);
}

void insertFront(Deque *d, int *data){
    InsertFront(d->l, data);
    d->n++;
}

void insertBack(Deque *d, int *data){
    InsertBack(d->l, data);
    d->n++;
}

void removeFront(Deque *d){
    RemoveFront(d->l);
    d->n--;
}

void removeBack(Deque *d){
    RemoveBack(d->l);
    d->n--;
}

void clear(Deque *d){
    while(!isEmpty(d)){
        removeFront(d);
    }
}

void print(const Deque *d){
    Print(d->l);
}

void printReverse(const Deque *d){
    PrintReverse(d->l);
}

void terminate(Deque *d){
    clear(d);
}
#endif