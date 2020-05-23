#include<iostream>
#include"Double_linked_list.h"
using namespace std;

template<typename T>
void Node<T>::SetNode(T x, Node<T> *nxt,Node<T> *prv){
    data = x;
    next = nxt;
    prev = prv;
}

template<typename T>
Double_linked_list<T>::Double_linked_list(){
    head = new Node<T>;
    tail = new Node<T>;
    head->next = tail;
    tail->prev = head;
    crnt = NULL;
}

template<typename T>
Double_linked_list<T>::~Double_linked_list(){
    while(IsEmpty())
        RemoveFront();
    delete head;
    delete tail;
}

template<typename T>
bool Double_linked_list<T>::IsEmpty(){
    return (head->next == tail || crnt == NULL);
}

template<typename T>
void Double_linked_list<T>::Insert(Node<T> *n, T data){
    Node<T> *new_node = new Node<T>;
    n->next = n->next->prev = new_node;
    new_node->SetNode(data, n->next, n);
    crnt = new_node;
}

template<typename T>
void Double_linked_list<T>::Remove(Node<T> *n){
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
}

template<typename T>
void Double_linked_list<T>::InsertFront(const T data){
    Insert(head, data);
    crnt = head->next;
}

template<typename T>
void Double_linked_list<T>::InsertBack(const T data){
    Insert(tail->prev, data);
    crnt = tail->prev;
}

template<typename T>
void Double_linked_list<T>::RemoveFront(){
    Remove(head->next);
}

template<typename T>
void Double_linked_list<T>::RemoveBack(){
    Remove(tail->prev);
}

template<typename T>
Node<T> *Double_linked_list<T>::Search(const T data){
    Node<T> *start = head;
    while(start->next != tail){
        if(start->data == data){
            crnt = start;
            return start;
        }
        start = start->next;
    }
    return NULL;
}

template<typename T>
bool Double_linked_list<T>::Next(){
    if(IsEmpty() || crnt->next == NULL)
        return false;
    crnt = crnt->next;
    return true;
}

template<typename T>
bool Double_linked_list<T>::Prev(){
    if(IsEmpty() || crnt->prev == NULL)
        return false;
    crnt = crnt->prev;
    return true;
}

template<typename T>
void Double_linked_list<T>::Printcurrent(){
    if(crnt == NULL)
        cout << "선택한 노드가 없습니다." << endl;
    cout << crnt->data << "입니다." << endl;
}

template<typename T>
void Double_linked_list<T>::Print(){
    Node<T> *start = head->next;
    while(start->next != tail){
        cout << start->data << " ";
        start = start->next;
    }
    putchar('\n');
}

template<typename T>
void Double_linked_list<T>::PrintReverse(){
    Node<T> *start = tail->prev;
    while(start->prev != head){
        cout << start->data << "입니다." << endl;
        start = start->prev;
    }
    putchar('\n');
}

template<typename T>
void Double_linked_list<T>::Clear(){
    while(head->next != NULL)
        RemoveFront();
    crnt = NULL;
}

template<typename T>
void Double_linked_list<T>::addSorted(const T data){
    Node<T> start = head->next;
    if(head->next == tail){
        Insert(head, data);
        crnt = head->next;
    }
    while(start->next != tail){
        if(start->data > data && start->next->data < data)
            Insert(start, data);
    start = start->next;
    }
}