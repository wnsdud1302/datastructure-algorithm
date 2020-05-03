#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int Initialize(Stack *s, int max){
    s->ptr = 0;
    if((s->stk = calloc(max, sizeof(int))) == NULL){
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

int Push(Stack *s, int x){
    if(s->ptr = s->max){
        return -1;
    }
    s->stk[s->ptr++] = x;
    return 0;
}

int Pop(Stack *s, int *x){
    if(s->ptr == 0){
        return -1;
    }
    *x = s->stk[s->ptr--];
    return 0;
}

int Peek(Stack *s, int *x){
    if(s->ptr == 0){
        return -1;
    }
    *x = s->stk[s->ptr-1];
    return 0;
}

void clear(Stack *s){
    s->ptr = 0;
}

int capacity(const Stack *s){
    return s->max;
}

int size(const Stack *s){
    return s->ptr;
}

int isEmpty(const Stack *s){
    return s->ptr <=0;
}

int isFull(const Stack *s){
    return s->ptr >= s->max;
}

int Search(const Stack *s, int x){
    for(int i = s->ptr-1; i>=0; i--){
        if(s->stk[i] == x)
        return i;
    }
    return -1;
}

void print(const Stack *s){
    for(int i = 0; i < s->ptr; i++){
        printf("%d ", s->stk[i]);
        putchar("\n");
    }
}
