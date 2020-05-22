#include<iostream>
#include"Double_linked_list.h"
using namespace std;

void Node::SetNode(int *x, Node *nxt, Node *prv){
    data = *x;
    next = nxt;
    prev = prv;
}

Double_linked_list::Double_linked_list(){
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

void Double_linked_list::Insert(Node *n, int *data){
    Node *new_node = new Node;
    Node *nxt = n->next;
    new_node->SetNode(data, nxt, n);
    n->next = nxt->prev = new_node;
}

void Double_linked_list::InsertFront(int *data){
    Insert(head, data);
}

void Double_linked_list::InsertBack(int *data){
    Insert(tail->prev, data);
}

void Double_linked_list::Remove(Node *n){
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
}

void Double_linked_list::RemoveFront(){
    Remove(head->next);
}

void Double_linked_list::RemoveBack(){
    Remove(tail->prev);
}

Node *Double_linked_list::Search(int *data){
    Node *start = head;
    while(start->next != tail){
        if(start->data == *data){
            return start;
            crnt = start;
        }
        start = start->next;
    }
    return NULL;
}

bool Double_linked_list::IsEmpty(){
    return head->next == tail;
}

bool Double_linked_list::next(){
    if(IsEmpty || crnt->next == NULL)
        return false;
    crnt = crnt->next;
    return true;
}

bool Double_linked_list::prev(){
    if(IsEmpty || crnt->prev == NULL)
        return false;
    crnt = crnt->prev;
    return true;
}

Double_linked_list::~Double_linked_list(){
    cout << "리스트를 종료합니다." << endl;
}