#ifndef INDEX_LINKED_LIST_H
#define INDEX_LINKED_LIST_H

typedef int Index;

typedef struct Node{
    int data;
    Index next;
    Index Dnext;
}Node;
typedef struct Index_Linked_list{
    Node *n;
    Index head;
    Index max;
    Index deleted;
    Index crnt;
}list;

void Initialize(list *l, int size);
Index Search(list *l, int *data);
void InsertFront(list *l, int *data);
void insertBack(list *l, int *data);
void RemoveFront(list *l);
void RemoveBack(list *l);
void RemoveCurrent(list *l);
void Clear(list *l);
void PrintCurrent(const list *l);
void Print(const list *l);
void Terminate(list *l);
#endif
