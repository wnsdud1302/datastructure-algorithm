#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include<stdio.h>
#include<stdlib.h>
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

static Dnode *AllocDnode(){
    return calloc(1, sizeof(Dnode));
}

static void SetNode(Dnode *n, int *data, Dnode *next, Dnode *prev){
    n->data = *data;
    n->next = next;
    n->prev = prev;
}


void Initialize(list *l){
    l->head  = AllocDnode();
    l->tail = AllocDnode();
    l->head->next = l->tail;
    l->tail->prev = l->head;
    l->crnt = l->head->next;
}

int IsEmpty(const list *l) {
    return l->head->next == l->tail;
}

const int Data(const list *l, int k){
    Dnode *start = l->head;
    for(int i = 0; i < k; i++){
        if(start == l->tail)
            break;
        start = start->next;
    }
    return start->data;
}

void Insert(list *l, Dnode *dn,int *data ){
    Dnode *new_node = AllocDnode();
    Dnode *nxt = dn->next;
    dn->next = nxt->prev = new_node;
    SetNode(new_node, data, nxt, dn);
    l->crnt = new_node;    
}

void InsertFront(list *l, int *data){
    Insert(l, l->head, data);
}

void InsertBack(list *l, int *data){
    Insert(l, l->tail->prev, data);
}

void Remove(list *l, Dnode *dn){
    dn->prev->next = dn->next;
    dn->next->prev = dn->prev;
    l->crnt = dn->next;
    free(dn);
}

void RemoveFront(list *l){
    Remove(l, l->head->next);
}

void RemoveBack(list *l){
    Remove(l, l->tail->prev);
}

Dnode *Search(list *l, int *data){
    Dnode *start = l->head;
    while( start->next != l->tail){
        if(start->data = *data){
            l->crnt = start;
            return start;
        }
        start = start->next;
    }
    return NULL;

}

int Next(list *l){
    if(IsEmpty(l) || l->crnt->next == l->tail)
        return 0;
    l->crnt = l->crnt->next;
    return 1;
}

int Prev(list *l){
    if(IsEmpty(l) || l->crnt->prev == NULL)
        return 0;
    l->crnt = l->crnt->prev;
    return 1;
}

void PrintCurrent(const list *l){
    if(IsEmpty(l))
        printf("선택한 노드가 없습니다.\n");
    else{
        printf("%d 입니다.\n", l->crnt->data);
    }
}

void Print(const list *l){
    Dnode *start = l->head->next;
    while(start != l->tail){
        printf("%d ", start->data);
        start = start->next;
    }
    putchar('\n');
}

void PrintReverse(const list *l){
    Dnode *start = l->tail->prev;
    while (start != l->head){
        printf("%d ", start->data);
        start = start->prev;
    }
    putchar('\n');
}

void Clear(list *l){
    while(l->head->next != NULL)
        RemoveFront(l);
    l->crnt = NULL;
}
 void Terminate(list *l){
    Clear(l);
 }
#endif
