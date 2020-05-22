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
    
}

Double_linked_list::~Double_linked_list(){
    cout << "리스트를 종료합니다." << endl;
}