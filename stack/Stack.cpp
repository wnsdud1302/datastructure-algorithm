#include <iostream>
#include<cstdlib>
#include "stack.h"

using namespace std;

Stack::Stack(){
    
}
Stack::Stack(int maxx){
    ptr = 0;
    if((stk = calloc(maxx, sizeof(int))) == NULL){
        max = 0;
        return -1;
    }
    max = maxx;
}
int Stack::push(int x){
    if(ptr >= max){
        return -1
    }
    stk[ptr++] = x
    return 0;
}

int pop
