#include<iostream>
#include"Linked_list.h"
using namespace std;

Linked_list::Linked_list(){
    head = NULL;
    crnt = NULL;
}

void Linked_list::InsertFront(int data){
    Node *tmpNode = new Node;
    tmpNode->data = data;
    tmpNode->next = head;
    head = crnt = tmpNode;
}

void Linked_list::InsertBack(int data){
    if(head == NULL)
        InsertFront(data);
    else{
        Node *tmpNode = new Node;
        Node *start = head;
        tmpNode->data = data;
        while(start->next != NULL)
            start = start->next;
        start->next = crnt = tmpNode;
    }
}

void Linked_list::RemoveFront(){
    Node *tmpNode = NULL;
    if(head != NULL){
        tmpNode = head->next;
        delete head;
    }
    head = tmpNode;
}

void Linked_list::RemoveBack(){
    if(head->next == NULL)
        RemoveFront();
    else{
        Node *tmpNode;
        Node *start = head;
        while(start->next != NULL){
            tmpNode = start;
            start = start->next;
        }
        tmpNode->next = NULL;
        delete start;
        crnt = tmpNode;
    }
}

void Linked_list::RemoveCurrent(){
    Node *start = head;
    if(start != NULL){
        if(start == crnt){
            RemoveFront();
        }
        else{
            while(start->next != crnt)
                start = start->next;
            start->next = crnt->next;
            delete crnt;
            crnt = start;
        }
    }
}

Node *Linked_list::Search(int data){
    Node *start = head;
    while(start != NULL){
        int n = 1;
        if(start->data = data){
            crnt = start;
            cout << n << "번째에 있습니다." << endl;
            return start;
        }
        start = start->next;
        n++;
    }
    return NULL;
}

void Linked_list::Clear(){
    Node *start = head;
    while(start !=NULL){
        delete start;
        start = start->next;
    }
    crnt = NULL;
}

void Linked_list::PrintCurrent(){
    int n = 1;
    Node *start = head;
    while(start != crnt){
        start = start->next;
        n++;
    }
    cout << "현재노드" << start->data << "는 " << n << "번째에 있습니다" << endl;
}

void Linked_list:: PrintNode(Node *n){
    cout << n->data << "입니다" << endl;

}

void Linked_list::Print(){
    Node *start = head;
    while(start != NULL){
        cout << start->data << " ";
        start = start->next;
    }
    cout << endl;
}

Linked_list::~Linked_list(){
    cout << "리스트를 삭제하였습니다." << endl;
}