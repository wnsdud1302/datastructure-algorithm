#ifndef ___Stack
#define ___Stack

typedef struct Stack{
    int max;
    int ptr;
    int *stk;
} Stack;

int Initialize(Stack *s, int max);
int Push(Stack *s, int x);
int Pop(Stack *s, int *x);
int Peek(Stack *s, int *x);
void clear(Stack *s);
int capacity(const Stack *s);
int size(const Stack *s);
int isEmpty(const Stack *s);
int isFull(const Stack *s);
int search(const Stack *s, int x);
void print(const Stack *s);
void Terminate(Stack *s);
#endif
