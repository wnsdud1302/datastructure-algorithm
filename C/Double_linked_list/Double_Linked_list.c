#include<stdio.h>
#include<stdlib.h>
#include"Double_Linked_list.h"

static Dnode *AllocDnode(){
    return calloc(1, sizeof(Dnode));
}

static void SetNode(Dnode *n, int *data, Dnode *next, Dnode *prev){
    n->data = *data;
    n->next = next;
    n->prev = prev;
}

static int IsEmpty(const list *l){
    return l->head->next == l->tail;
}

void Initialize(list *l){
    l->head = NULL;
    l->tail = NULL;
    l->crnt = l->head->next;
    l->head->next = l->tail;
    l->tail->prev = l->head;
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
    l->crnt = dn->prev;
    free(dn);
}

void RemoveFront(list *l){
    Remove(l, l->head->next);
}

void RemoveBack(list *l){
    Remove(l, l->tail->prev);
}

Dnode *search(list *l, int *data){
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
    Dnode *start = l->head;
    while(start->next != l->tail){
        printf("%d ", start->data);
        start = start->next;
    }
    putchar('\n');
}

void PrintReverse