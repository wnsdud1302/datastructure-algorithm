#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include<iostream>
#include<string>
using namespace std;

template <typename T> class Double_linked_list;

template <typename T>
class Node{
public:
    void SetNode(const T& x,Node<T> *nxt,Node<T> *prv);
private:    
    T data;
    Node<T> *next;
    Node<T> *prev;
    friend class Double_linked_list<T>;

};
template <typename T>
class Double_linked_list{
public:
    Double_linked_list();
    ~Double_linked_list();
    bool IsEmpty() const;
    const T& Front() const;
    const T& Back() const;
    const T& Data(int k) const;
    void InsertFront(const T& data);
    void InsertBack(const T& data);
    void RemoveFront();
    void RemoveBack();
    Node<T> *Search(const T& data);
    bool Next();
    bool Prev();
    void Printcurrent();
    void Print();
    void PrintReverse();
    void Clear();
    void addSorted(const T& data);
private:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *crnt;
protected:
    void Insert(Node<T> *n,const T& data);
    void Remove(Node<T> *n);

};

template<typename T>
void Node<T>::SetNode(const T& x, Node<T> *nxt, Node<T> *prv){
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
    while(!IsEmpty())
        RemoveFront();
    delete head;
    delete tail;
}

template<typename T>
bool Double_linked_list<T>::IsEmpty() const{
    return (head->next == tail || crnt == NULL);
}

template<typename T>
const T& Double_linked_list<T>::Front() const{
    return head->next->data;
}

template<typename T>
const T& Double_linked_list<T>::Back() const{
    return tail->prev->data;
}

template<typename T>
const T& Double_linked_list<T>::Data(int k) const{
    Node<T> *start = head;
    for(int i = 0; i < k; i++){
        if(start == tail)
            break;
        start = start->next;
    }
    return start->data;
}

template<typename T>
void Double_linked_list<T>::Insert(Node<T> *n,const T& data){
    Node<T> *new_node = new Node<T>;
    Node<T> *nxt = n->next;
    n->next = n->next->prev = new_node;
    new_node->SetNode(data, nxt, n);
    crnt = new_node;
}

template<typename T>
void Double_linked_list<T>::Remove(Node<T> *n){
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
}

template<typename T>
void Double_linked_list<T>::InsertFront(const T& data){
    Insert(head, data);
    crnt = head->next;
}

template<typename T>
void Double_linked_list<T>::InsertBack(const T& data){
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
Node<T> *Double_linked_list<T>::Search(const T& data){
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
    while(start != tail){
        cout << start->data << " <=> ";
        start = start->next;
    }
    putchar('\n');
}

template<typename T>
void Double_linked_list<T>::PrintReverse(){
    Node<T> *start = tail->prev;
    while(start != head){
        cout << start->data << " <=> ";
        start = start->prev;
    }
    putchar('\n');
}

template<typename T>
void Double_linked_list<T>::Clear(){
    while(head->next != tail)
        RemoveFront();
    crnt = NULL;
}

template<typename T>
void Double_linked_list<T>::addSorted(const T& data){
    Node<T> *start = head->next;
    if(head->next == tail){
        Insert(head, data);
        crnt = head->next;
    }
    else{
        while(start->next != tail){
            if(start->data > data && start->next == tail){
                Insert(start, data);
                break;
            }
            else if(start->data > *data && start->next->data < data){
                Insert(start, data);
                break;
            }
        start = start->next;
        }
    }
}
#endif
