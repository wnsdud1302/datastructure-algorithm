#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

typedef struct Dnode
{
    int data;
    struct Node *next;
    struct Node *prev;
}Dnode;

typedef struct Double_linked_list{
    Dnode *head;
    Dnode *tail;
    Dnode *crnt;
}list;

void Initialize(list *l);
void SetNode(Dnode *n, const int *data, const Dnode *next, const Dnode *prev);
void InsertFront(list *l);
void Insert(list *l, Dnode *dn, const int *data);
void InsertBack(list *l);
void Remove(list *l, Dnode *dn);
void RemoveFront(list *l);
void RemoveBack(list *l);
Dnode *search(list *l, int *data);
int Next(list *l);
int Prev(list *l);
void PrintCurrent(list *l);
void Print(list *l);
void PrintReverse(list *l);
void Clear(list *l);
void Terminate(list *l);

#endif
