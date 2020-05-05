#include <stdio.h>
#include<stdlib.h>
#include "DoubleStack.h"

int Initialize(DoubleStack *ds, int max){
    ds->fptr = 0;
    ds->rptr = max-1;
    if ((ds->stk = calloc(max, sizeof(int))) == NULL){
        return -1;
    }
    ds->max = max;
    return 0;
}
int FrontPush(DoubleStack *ds, int x){
    if (ds->fptr == ds->max)
        return -1;
    ds->stk[ds->fptr++] = x;
    return 0;
}
int RearPush(DoubleStack *ds, int x){
    if(ds->rptr == ds->fptr)
        return -1;
    ds->stk[ds->rptr--] = x;
    return 0;
}
int FrontPop(DoubleStack *ds, int *x){
    if(ds->fptr == 0)
        return -1;
    *x = ds->stk[ds->fptr--];
    return 0;
}
int RearPop(DoubleStack *ds, int *x){
    if(ds->rptr == ds->max -1)
        return -1;
    *x = ds->stk[ds->rptr++];
    return 0;
}
int FrontPeek(DoubleStack *ds, int *x){
        if(ds->fptr == 0){
        return -1;
    }
    *x = ds->stk[ds->fptr-1];
    return 0;
}
int RearPeek(DoubleStack *ds, int *x){
    if(ds->rptr == ds->max - 1)
        return -1;
    *x = ds->stk[ds->rptr+1];
}
int capacity(const DoubleStack *ds){
    return ds->max;
}
int size(const DoubleStack *ds){
    return ds->fptr + (63 - ds->rptr);
}
int isEmpty(const DoubleStack *ds){
    return ds->fptr + ds->rptr <= 0;
}
int isFull(const DoubleStack *ds){
    return ds->fptr + ds->rptr >= ds->max;
}
int FrontSearch(const DoubleStack *ds, int x){
    for(int i = ds->fptr-1; i>=0; i--){
        if(ds->stk[i] == x)
        return i;
    }
    return -1;
}
int RearSearch(const DoubleStack *ds, int x){
    for(int i = ds->rptr+1; i <= ds->max; i++){
        if(ds->stk[i] == x)
            return i;
    }
    return -1;
}
void FrontPrint(const DoubleStack *ds){
        for(int i = 0; i < ds->fptr; i++){
        printf("%d ", ds->stk[i]);
        putchar('\n');
        }
}
void RearPrint(const DoubleStack *ds){
        for(int i = ds->max ; i > ds->rptr ; i--){
        printf("%d ", ds->stk[i]);
        putchar('\n');
        }
}
void Terminate(DoubleStack *ds){
        if(ds->stk != NULL){
        free(ds->stk);
    }
    ds->max = ds->fptr = ds->rptr = 0;
}