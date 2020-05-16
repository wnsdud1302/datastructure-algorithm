#ifndef LINKED_LIST_H
#define LINKED_KIST_H
typedef struct Node
{
    int data;
    struct Node *next; // 자기참조 struct를 붙여야함 아직 정의가 않끝났기때문
}Node;

typedef struct Linked_list{
    Node *head;
    Node *crnt;
}Linked_list;

void Initialize(Linked_list *list);
void InsertFront(Linked_list *list, int *data);
void InsertBack(Linked_list *list, int *data);
void RemoveFront(Linked_list *list);
void RemoveBack(Linked_list *list);
void RemoveCurrent(Linked_list *list);
int Search(Linked_list *list, int *data);
void Clear(Linked_list *list);
void PrintCurrent(const Linked_list *list);
void Print(const Linked_list *list);
void Terminate(Linked_list *list);
#endif
