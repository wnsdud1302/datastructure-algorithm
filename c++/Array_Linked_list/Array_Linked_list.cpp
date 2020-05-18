#include<iostream>
#include"Array_Linked_list.h"
using namespace std;

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

void Arraylinkedlist::InsertFront(int *data){
    Index tmp = head;
    head = crnt = GetIndex();
    n[head].SetNode(data, tmp);
}

void Arraylinkedlist::InsertBack(int *data){
    Index start = head;
    if(start == Null)
        InsertFront(data);
    else{
        while(n[start].next != Null)
            start = n[start].next;
    n[start].next = crnt = GetIndex();
    n[n[start].next].SetNode(data, Null);
    }
}

void Arraylinkedlist::RemoveFront(){
    if(head != Null){
        Index tmp = n[head].next;
        DeleteIndex(head);
        head = crnt = tmp;
    }
}

void Arraylinkedlist::RemoveBack(){
    Index start = head;
    if(start != Null){
        if(n[start].next == Null)
            RemoveFront();
        else{
            Index tmp;
            while(n[start].next != Null){
                tmp = start;
                start = n[start].next;
            }
            n[start].next = Null;
            DeleteIndex(start);
            crnt = tmp;
        }
    }
}

void Arraylinkedlist::RemoveCurrent(){
    if(head !=Null){
        if(head == crnt){
            RemoveFront();
        }
        else{
            Index start = head;
            while(n[start].next != crnt)
                start = n[start].next;
            n[start].next = n[crnt].next;
            DeleteIndex(crnt);
            crnt = start;
        }
    }
}

void Arraylinkedlist::Clear(){
    while(head != Null){
        RemoveFront();
    }
    crnt = Null;
}

void Arraylinkedlist::PrintNode(Index idx){
    cout << n[idx].data << "입니다." << endl;
}

void Arraylinkedlist::PrintCurrent(){
    if(crnt == Null)
        cout << "선택한 노드가 없습니다." << endl;
    else
    {
        cout << n[crnt].data << "입니다." << endl;
    }
}


void Arraylinkedlist::Print(){
    Index start = head;
    if(start == Null)
        cout << "노드가 없습니다." << endl;
    while(n[start].next != Null){
        cout << n[start].data << " ";
        start = n[start].next;
    }
    cout << endl;
}

Arraylinkedlist::~Arraylinkedlist(){
    cout << " 리스트를 종료합니다." << endl;
}

