#ifndef LINKED_LIST_H
#define LINKED_KIST_H
typedef struct Node
{
    int data;
    Node *next;
}Node;

typedef struct Linked_list{
    Node *head;
}Linked_list;

int Initialize(Linked_list *list);
int InsertFront(Linked_list *list, int data);
int InsertBack(Linked_list *list, int data);
void RemoveFront(Linked_list *list);
void RemoveBack(Linked_list *list);
void RemoveCurrent(Linked_list *list);
void clear(Linked_list *list);
void Print(const Linked_list *list);
void Terminate(Linked_list *list);
#endif
