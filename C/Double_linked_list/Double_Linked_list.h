#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

typedef struct Dnode{
    int data;
    struct Dnode *next;
    struct Dnode *prev;
}Dnode;

typedef struct Double_linked_list{
    Dnode *head;
    Dnode *tail;
    Dnode *crnt;
}list;

void Initialize(list *l);
void Insert(list *l, Dnode *dn, int *data);
void InsertFront(list *l, int *data);
void InsertBack(list *l, int *data);
void Remove(list *l, Dnode *dn);
void RemoveFront(list *l);
void RemoveBack(list *l);
Dnode *search(list *l, int *data);
int Next(list *l);
int Prev(list *l);
void PrintCurrent(const list *l);
void Print(const list *l);
void PrintReverse(const list *l);
void Clear(list *l);
void Terminate(list *l);

#endif
