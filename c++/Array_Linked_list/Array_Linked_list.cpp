#include<iostream>
#include"Array_Linked_list.h"
using namespace std;
static void SetNode(Node *n, const int *data,const Index next){
    n->data = *data;
    n->next = next;
}
void Node::SetNode(const int *x, const Index nxt){
    data = *x;
    next = nxt;
}

Arraylinkedlist::Arraylinkedlist(int size){
    n = new Node[size];
    head = Null;
    max = Null;
    crnt = Null;
    deleted = Null;
}
Index Arraylinkedlist::GetIndex(){
    if(deleted == Null)
        return ++max;
        else{
            Index rec = deleted;
            deleted = n[rec].next;
            return rec;
        }
    
}

Index Arraylinkedlist::DeleteIndex(Index idx){
    if(deleted == Null){
        deleted = idx;
        n[idx].next = Null;
    }
    else{
        Index tmp = deleted;
        deleted = idx;
        n[idx].Dnext = tmp;
    }
}

Index Arraylinkedlist::Search(int *data){
    Index start = head;
    while(start != Null){
        if(n[start].data = *data){
            crnt = start;
            return start;
        }
        start = n[start].next;
    }
    return Null;
}

void Arraylinkedlist::InseartFront(int *data){
    Index tmp = head;
    head = crnt = GetIndex();
    SetNode(&n[head], data, tmp);
}

void Arraylinkedlist::InseartBack(int *data){
    Index start = head;
    if(start == Null)
        InseartFront(data);
    else{
        while(n)
    }
}