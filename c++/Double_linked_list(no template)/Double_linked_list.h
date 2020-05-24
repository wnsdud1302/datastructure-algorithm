#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include<iostream>
using namespace std;

class Node{
public:
    void SetNode(int x,Node *nxt, Node *prv);
private:
    int data;
    Node *next;
    Node *prev;
    friend class Double_linked_list;
};

class Double_linked_list{
public:
    Double_linked_list();
    ~Double_linked_list();
    void InsertFront(int data);
    void InsertBack(int data);
    void RemoveFront();
    void RemoveBack();
    bool IsEmpty();
    void Print();
    void PrintReverse();
    void Clear();
    void AddSorted(int data);
protected:
    Node *head;
    Node *tail;
    void Insert(Node *n, int data);
    void Remove(Node *n);
};

void Node::SetNode(int x, Node *nxt, Node *prv){
    data = x;
    next = nxt;
    prev = prv;

}

Double_linked_list::Double_linked_list(){
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

Double_linked_list::~Double_linked_list(){
    Clear();
    delete head;
    delete tail;
}

void Double_linked_list::Insert(Node *n, int data){
    Node *new_node = new Node;
    Node *nxt = n->next;
    n->next = nxt->prev = new_node;
    new_node->SetNode(data, nxt, n);
}

void Double_linked_list::Remove(Node *n){
    Node *prv = n->prev;
    Node *nxt = n->next;
    nxt->prev = prv;
    prv->next = nxt;
    delete n;
}

void Double_linked_list::InsertFront(int data){
    Insert(head, data);
}

void Double_linked_list::InsertBack(int data){
    Insert(tail->prev, data);
}

void Double_linked_list::RemoveFront(){
    Remove(head->next);
}

void Double_linked_list::RemoveBack(){
    Remove(tail->prev);
}

bool Double_linked_list::IsEmpty(){
    return(head->next == tail);
}

void Double_linked_list::Print(){
    Node *start = head->next;
    while(start != tail){
        cout << start->data << " <=> ";
        start = start->next;
    }
    putchar('\n');
}

void Double_linked_list::PrintReverse(){
    Node *start = tail->prev;
    while(start != head){
        cout << start->data << " <=> ";
        start = start->prev;
    }
    putchar('\n');
}

void Double_linked_list::Clear(){
    while(head->next != tail)
        RemoveFront();
}

void Double_linked_list::AddSorted(int data){
    Node *start = head;
        if(start->next == tail){
        Insert(head, data);
    }
    else{
        while(start->next != tail){
            if(start->data > data && start->next == tail)
                Insert(start, data);
            else if(start->data > data && start->next->data < data)
                Insert(start, data);
        start = start->next;
        }
    }
}

#endif