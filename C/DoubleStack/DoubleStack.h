#ifndef DoubleStack_H
#define DoubleStack_H

typedef struct DoubleStack{
    int max;
    int fptr;
    int rptr;
    int *stk;
} DoubleStack;

int Initialize(DoubleStack *ds, int max);
int FrontPush(DoubleStack *ds, int x);
int RearPush(DoubleStack *ds, int x);
int FrontPop(DoubleStack *ds, int *x);
int RearPop(DoubleStack *ds, int *x);
int FrontPeek(DoubleStack *ds, int *x);
int RearPeek(DoubleStack *ds, int *x);
int capacity(const DoubleStack *ds);
int size(const DoubleStack *ds);
int isEmpty(const DoubleStack *ds);
int isFull(const DoubleStack *ds);
int FrontSearch(const DoubleStack *ds, int x);
int RearSearch(const DoubleStack *ds, int x);
void Frontprint(const DoubleStack *ds);
void RearPrint(const DoubleStack *ds);
void Terminate(DoubleStack *ds);

#endif
