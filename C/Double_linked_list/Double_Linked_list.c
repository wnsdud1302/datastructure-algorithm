#include<stdio.h>
#include<stdlib.h>
#include"Double_Linked_list.h"

static Dnode *AllocDnode(){
    return calloc(1, sizeof(Dnode));
}

void Initialize(list *l){
    Dnode *dummyNode = AllocDnode();
    l->head  = l->crnt = dummyNode;
    dummyNode->prev = dummyNode->next = dummyNode;
}

void SetNode(Dnode *n, int *data, Dnode *next, Dnode *prev){
    n->data = *data;
    n->next = next;
    n->prev = prev;
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
    Insert(l, l->head->prev, data);
}

void Remove(list *l, Dnode *dn){
    dn->prev->next = dn->next;
    dn->next->prev = dn->prev;
    free(dn);
}